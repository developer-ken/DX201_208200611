/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

/**
 ******************************************************************************
 * NO LICENSE
 * 本项目包含至少一个未以任何开源协议授权的第三方源文件。为规避相关风险，本项目也不以任何开源协议授权。
 * 根据相关规定，本项目可以用于学习目的。除非明确获得授权，否则不应用于其他目的。
 *
 * This repo contains at least one thirdpart file that is not licensed opensource.
 * Use this repo only in educational purpose unless licensed.
 ******************************************************************************
 */

/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stm32f1xx_ll_rcc.h>
#include "SimplePage_208200611.h"
#include "oled_208200611.h"
#include "bitmaps_208200611.h"
#include "flappy_208200611.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define MLCNT 2
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
IWDG_HandleTypeDef hiwdg;

RTC_HandleTypeDef hrtc;

extern UserInputHandler Flappy_ihan;
/* USER CODE BEGIN PV */
volatile SimplePage *CurrentPage;
SimplePage *SplashScreen, *HomeMenu, *TimerMenu, *Multilayer[MLCNT], *AboutMenu,
		*ErrorPage, *GHQrpage, *HomeQrpage, *Game;
u32 LastIntrTimestamp;

u32 AntiVibLen = 200;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_RTC_Init(void);
static void MX_IWDG_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void GoBack(SimplePage *page) {
	if (page->Prev != NULL) {
		CurrentPage = page->Prev;
		CurrentPage->Changed = true;
	}
}

void ResetGdriver(void *_) { //用于手动重置屏幕
	OLED_Init();
	OLED_Display_On();
	CurrentPage->Changed = true; //触发屏幕重绘
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	u32 now = NativeTimestampMs();
	if (now - LastIntrTimestamp < AntiVibLen)
		return;
	LastIntrTimestamp = now;

	if (CurrentPage->InputHandler != NULL) {
		switch (GPIO_Pin) {
		case UP_Pin:
			CurrentPage->PendingRawInput = CurrentPage->InputHandler->Up;
			break;
		case DWN_Pin:
			CurrentPage->PendingRawInput = CurrentPage->InputHandler->Down;
			break;
		case LFT_Pin:
			CurrentPage->PendingRawInput = CurrentPage->InputHandler->Left;
			break;
		case RHT_Pin:
			CurrentPage->PendingRawInput = CurrentPage->InputHandler->Right;
			break;
		case MID_Pin:
			CurrentPage->PendingRawInput = CurrentPage->InputHandler->Mid;
			break;
		case KPD_RST_Pin:
			CurrentPage->PendingRawInput = CurrentPage->InputHandler->Reset;
			break;
		case SET_Pin:
			CurrentPage->PendingRawInput = CurrentPage->InputHandler->Set;
			break;
		}
		return;
	}

	switch (GPIO_Pin) {
	case UP_Pin:
		MenuSelectPrev(CurrentPage);
		break;
	case DWN_Pin:
		MenuSelectNext(CurrentPage);
		break;
	case LFT_Pin:
		GoBack(CurrentPage);
		break;
	case RHT_Pin:

		break;
	case MID_Pin:
		MenuClick(CurrentPage);
		break;
	case KPD_RST_Pin:
		NVIC_SystemReset();
		break;
	case SET_Pin:
		CurrentPage = HomeMenu;
		CurrentPage->Changed = true;
		break;
	}
}

void SwitchPage(Label *source) {
	if (source->LinkTo != NULL) {
		source->LinkTo->Prev = CurrentPage;
		CurrentPage = source->LinkTo;
		CurrentPage->Changed = true;
	}
}

u32 CurrentTimestamp() {
	RTC_TimeTypeDef time;
	RTC_DateTypeDef date;
	struct tm tm_new;
	HAL_RTC_GetTime(&hrtc, &time, RTC_FORMAT_BIN);
	HAL_RTC_GetDate(&hrtc, &date, RTC_FORMAT_BIN);
	tm_new.tm_sec = time.Seconds;
	tm_new.tm_min = time.Minutes;
	tm_new.tm_hour = time.Hours;
	tm_new.tm_mday = date.Date;
	tm_new.tm_mon = date.Month - 1;
	tm_new.tm_year = date.Year + 100;
	return mktime(&tm_new);
}

inline u32 NativeTimestampMs() {
	return HAL_GetTick();
}

volatile u8 IsTimerRunning;
u32 StartTs = 0, LastTs = 0;
char timestrbuf[16];

void TimerStart() {
	IsTimerRunning = true;
	StartTs = NativeTimestampMs();
	TimerMenu->Line2->Text = "Zero";
	TimerMenu->Line2->Changed = true;
}

void TimerStop() {
	IsTimerRunning = 0;
	TimerMenu->Line2->Text = "Start";
	TimerMenu->Line2->Changed = true;
}

void TimerUpdate(SimplePage *page) {
	if (IsTimerRunning) {
		u32 now = NativeTimestampMs();
		if (now != LastTs) {
			u32 len1; // = strlen(timestrbuf);
			itoa(((now - StartTs) / 1000), timestrbuf, 10);
			len1 = strlen(timestrbuf);
			timestrbuf[len1] = '.';
			itoa(((now - StartTs) % 1000), timestrbuf + len1 + 1, 10);
			page->Line1->Text = timestrbuf;
			page->Line1->Changed = true;
			LastTs = now;
		}
	}
}

void DrawQrGH(SimplePage *page) {
	if (!page->Changed)
		return;
	OLED_Clear();
	OLED_DrawBMP(32, 0, 64 + 32, 8, GHQR);
	page->Changed = false;
}

void DrawQr(SimplePage *page) {
	if (!page->Changed)
		return;
	OLED_Clear();
	OLED_DrawBMP(32, 0, 64 + 32, 8, HMQR);
	page->Changed = false;
}

void Splash(SimplePage *page) {
	if (NativeTimestampMs() > 1000) {
		CurrentPage = HomeMenu;
		return;
	}
	if (!page->Changed)
		return;
	OLED_Clear();
	OLED_DrawBMP(0, 0, 128, 8, SPLASHBM);
	page->Changed = false;
}
/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void) {
	/* USER CODE BEGIN 1 */
	//初始化各个界�??
	HomeMenu = EmptyPage();
	TimerMenu = EmptyPage();
	AboutMenu = EmptyPage();
	ErrorPage = EmptyPage();
	GHQrpage = EmptyPage();
	HomeQrpage = EmptyPage();
	SplashScreen = EmptyPage();
	Game = EmptyPage();
	CurrentPage = SplashScreen;
	int ii = 0;
	SimplePage *lastpage = EmptyPage();
	for (ii = 0; ii < MLCNT; ii++) {
		SimplePage *page = EmptyPage();
		Multilayer[ii] = page;
		u8 *bufii = (u8*) malloc(3 * sizeof(u8));
		itoa(ii, bufii, 10);
		page->Title = bufii;
		page->Line1->Text = "->Child Menu";
		page->Line2->Text = "->Child Menu";
		page->Line3->Text = "->Child Menu";

		if (lastpage != NULL) {
			lastpage->Line1->LinkTo = page;
			lastpage->Line1->OnClick = SwitchPage;
			lastpage->Line2->LinkTo = page;
			lastpage->Line2->OnClick = SwitchPage;
			lastpage->Line3->LinkTo = page;
			lastpage->Line3->OnClick = SwitchPage;
		}
		lastpage = page;
	}
	lastpage->Line1->Text = "Game";
	lastpage->Line1->LinkTo = Game;
	lastpage->Line1->OnClick = SwitchPage;

	/*
	 Multilayer[MLCNT-1].Line2->Text = "No more child";
	 Multilayer[MLCNT-1].Line2->LinkTo = NULL;
	 Multilayer[MLCNT-1].Line2->OnClick = NULL;
	 */

	HomeMenu->Title = "Home";

	HomeMenu->Line1->Text = "Timer";
	HomeMenu->Line1->LinkTo = TimerMenu;
	HomeMenu->Line1->OnClick = SwitchPage;

	HomeMenu->Line2->Text = "Multilayer";
	HomeMenu->Line2->LinkTo = *Multilayer;
	HomeMenu->Line2->OnClick = SwitchPage;

	HomeMenu->Line3->Text = "About";
	HomeMenu->Line3->LinkTo = AboutMenu;
	HomeMenu->Line3->OnClick = SwitchPage;

	TimerMenu->Title = "Timer";
	TimerMenu->SelectedIndex = 2; //Line1 = 1, Line2 = 2,etc
	TimerMenu->BeforeUpdate = TimerUpdate;

	TimerMenu->Line1->Text = "0";
	TimerMenu->Line1->Selectable = false; // 不可选中

	TimerMenu->Line2->Text = "Start";
	TimerMenu->Line2->OnClick = TimerStart;

	TimerMenu->Line3->Text = "Stop";
	TimerMenu->Line3->OnClick = TimerStop;

	AboutMenu->Title = "About";

	AboutMenu->Line1->Text = "Blog  msgp.tech";
	//AboutMenu->Line1->Selectable = false; // 不可选中
	AboutMenu->Line1->LinkTo = HomeQrpage;
	AboutMenu->Line1->OnClick = SwitchPage;

	AboutMenu->Line2->Text = "Github  Dev_ken";
	//AboutMenu->Line2->Selectable = false; // 不可选中
	AboutMenu->Line2->LinkTo = GHQrpage;
	AboutMenu->Line2->OnClick = SwitchPage;

	AboutMenu->Line3->Text = "208200611";
	AboutMenu->Line3->Selectable = false; // 不可选中
	AboutMenu->Line3->Centered = true;

	ErrorPage->Title = "IWDG RESET";

	ErrorPage->Line1->Text = "An watchdog over";
	ErrorPage->Line1->Selectable = false; // 不可选中

	ErrorPage->Line2->Text = "flow detected.";
	ErrorPage->Line2->Selectable = false; // 不可选中

	ErrorPage->Line3->Text = "- Press SET -";
	ErrorPage->Line3->Selectable = false; // 不可选中
	ErrorPage->Line3->Centered = true; // 居中

	HomeQrpage->SelfRender = true;
	HomeQrpage->BeforeUpdate = DrawQr;

	GHQrpage->SelfRender = true;
	GHQrpage->BeforeUpdate = DrawQrGH;

	SplashScreen->SelfRender = true;
	SplashScreen->BeforeUpdate = Splash;

	Game->SelfRender = true;
	Game->BeforeUpdate = Flappy_Update;
	Game->InputHandler = &Flappy_ihan;

	if (LL_RCC_IsActiveFlag_IWDGRST()) {
		LL_RCC_ClearResetFlags();
		CurrentPage = ErrorPage;
		CurrentPage->Changed = true;
	}
	/* USER CODE END 1 */

	/* MCU Configuration--------------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();

	/* USER CODE BEGIN Init */

	/* USER CODE END Init */

	/* Configure the system clock */
	SystemClock_Config();

	/* USER CODE BEGIN SysInit */

	/* USER CODE END SysInit */

	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	MX_RTC_Init();
	MX_IWDG_Init();
	/* USER CODE BEGIN 2 */
	OLED_Init();
	OLED_Display_On();
	/* USER CODE END 2 */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	while (1) {
		HAL_IWDG_Refresh(&hiwdg);
		UpdatePage(CurrentPage);
		/* USER CODE END WHILE */

		/* USER CODE BEGIN 3 */
	}
	/* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void) {
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };
	RCC_PeriphCLKInitTypeDef PeriphClkInit = { 0 };

	/** Initializes the RCC Oscillators according to the specified parameters
	 * in the RCC_OscInitTypeDef structure.
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI
			| RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.LSIState = RCC_LSI_ON;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/** Initializes the CPU, AHB and APB buses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK) {
		Error_Handler();
	}
	PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_RTC;
	PeriphClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;
	if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK) {
		Error_Handler();
	}
}

/**
 * @brief IWDG Initialization Function
 * @param None
 * @retval None
 */
static void MX_IWDG_Init(void) {

	/* USER CODE BEGIN IWDG_Init 0 */

	/* USER CODE END IWDG_Init 0 */

	/* USER CODE BEGIN IWDG_Init 1 */

	/* USER CODE END IWDG_Init 1 */
	hiwdg.Instance = IWDG;
	hiwdg.Init.Prescaler = IWDG_PRESCALER_4;
	hiwdg.Init.Reload = 4095;
	if (HAL_IWDG_Init(&hiwdg) != HAL_OK) {
		Error_Handler();
	}
	/* USER CODE BEGIN IWDG_Init 2 */

	/* USER CODE END IWDG_Init 2 */

}

/**
 * @brief RTC Initialization Function
 * @param None
 * @retval None
 */
static void MX_RTC_Init(void) {

	/* USER CODE BEGIN RTC_Init 0 */

	/* USER CODE END RTC_Init 0 */

	RTC_TimeTypeDef sTime = { 0 };
	RTC_DateTypeDef DateToUpdate = { 0 };

	/* USER CODE BEGIN RTC_Init 1 */

	/* USER CODE END RTC_Init 1 */

	/** Initialize RTC Only
	 */
	hrtc.Instance = RTC;
	hrtc.Init.AsynchPrediv = RTC_AUTO_1_SECOND;
	hrtc.Init.OutPut = RTC_OUTPUTSOURCE_NONE;
	if (HAL_RTC_Init(&hrtc) != HAL_OK) {
		Error_Handler();
	}

	/* USER CODE BEGIN Check_RTC_BKUP */

	/* USER CODE END Check_RTC_BKUP */

	/** Initialize RTC and set the Time and Date
	 */
	sTime.Hours = 0x0;
	sTime.Minutes = 0x0;
	sTime.Seconds = 0x0;

	if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BCD) != HAL_OK) {
		Error_Handler();
	}
	DateToUpdate.WeekDay = RTC_WEEKDAY_MONDAY;
	DateToUpdate.Month = RTC_MONTH_JANUARY;
	DateToUpdate.Date = 0x1;
	DateToUpdate.Year = 0x0;

	if (HAL_RTC_SetDate(&hrtc, &DateToUpdate, RTC_FORMAT_BCD) != HAL_OK) {
		Error_Handler();
	}
	/* USER CODE BEGIN RTC_Init 2 */

	/* USER CODE END RTC_Init 2 */

}

/**
 * @brief GPIO Initialization Function
 * @param None
 * @retval None
 */
static void MX_GPIO_Init(void) {
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };
	/* USER CODE BEGIN MX_GPIO_Init_1 */
	/* USER CODE END MX_GPIO_Init_1 */

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(ILED_GPIO_Port, ILED_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOB, DC_Pin | RES_Pin | D1_Pin | D0_Pin,
			GPIO_PIN_RESET);

	/*Configure GPIO pin : ILED_Pin */
	GPIO_InitStruct.Pin = ILED_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(ILED_GPIO_Port, &GPIO_InitStruct);

	/*Configure GPIO pins : DC_Pin RES_Pin D1_Pin D0_Pin */
	GPIO_InitStruct.Pin = DC_Pin | RES_Pin | D1_Pin | D0_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	/*Configure GPIO pins : KPD_RST_Pin SET_Pin MID_Pin RHT_Pin */
	GPIO_InitStruct.Pin = KPD_RST_Pin | SET_Pin | MID_Pin | RHT_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	/*Configure GPIO pins : LFT_Pin DWN_Pin UP_Pin */
	GPIO_InitStruct.Pin = LFT_Pin | DWN_Pin | UP_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	/* EXTI interrupt init*/
	HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

	/* USER CODE BEGIN MX_GPIO_Init_2 */
	/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void) {
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1) {
	}
	/* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
