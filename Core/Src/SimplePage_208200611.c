/* **********************************
 *	SimplePage 简易GUI框架
 *	by 邓君卓 208200611
 * ********************************** */

#include "SimplePage_208200611.h"
#include "oled_208200611.h"

void _SIMPLEPAGE_PGSync(SimplePage *page);
void _SIMPLEPAGE_PGSync_rc(SimplePage *page, int dir);
void EmptyOut(u8 x, u8 y, u8 lastlen, u8 currentlen, u8 Inv);

inline void EmptyOut(u8 x, u8 y, u8 lastlen, u8 currentlen, u8 Inv) {
	for (; currentlen <= lastlen; currentlen++) {
		//OLED_ShowChar(x + currentlen * 8, y, Inv, ' ');
		OLED_ShowChar(x + currentlen * 8, y, 0, ' ');
	}
}

// 渲染页面
inline void RenderPage(SimplePage *page) {
	_SIMPLEPAGE_PGSync(page);
	u8 anychange = 0;
	if (page->Changed) {
		OLED_Clear();
		OLED_ShowString(Center(page->Title), 0, 0, page->Title);
		OLED_ShowString(page->Line1->Centered ? Center(page->Line1->Text) : 0,
				2, page->Line1->Selected, page->Line1->Text);
		OLED_ShowString(page->Line2->Centered ? Center(page->Line2->Text) : 0,
				4, page->Line2->Selected, page->Line2->Text);
		OLED_ShowString(page->Line3->Centered ? Center(page->Line3->Text) : 0,
				6, page->Line3->Selected, page->Line3->Text);
		page->Line1->Changed = 0;
		page->Line2->Changed = 0;
		page->Line3->Changed = 0;
		page->Line1->LastLen = strlen(page->Line1->Text);
		page->Line2->LastLen = strlen(page->Line2->Text);
		page->Line3->LastLen = strlen(page->Line3->Text);
		page->Changed = 0;
		anychange++;
	}

	if (page->Line1->Changed) {
		EmptyOut(page->Line3->Centered ? Center(page->Line1->Text) : 0, 2, page->Line1->LastLen, strlen(page->Line1->Text),
				page->Line1->Selected);
		OLED_ShowString(page->Line3->Centered ? Center(page->Line1->Text) : 0, 2, page->Line1->Selected, page->Line1->Text);
		page->Line1->Changed = 0;
		page->Line1->LastLen = strlen(page->Line1->Text);
		anychange++;
	}

	if (page->Line2->Changed) {
		EmptyOut(page->Line3->Centered ? Center(page->Line2->Text) : 0, 4, page->Line2->LastLen, strlen(page->Line2->Text),
				page->Line2->Selected);
		OLED_ShowString(page->Line3->Centered ? Center(page->Line2->Text) : 0, 4, page->Line2->Selected, page->Line2->Text);
		page->Line2->Changed = 0;
		page->Line2->LastLen = strlen(page->Line2->Text);
		anychange++;
	}

	if (page->Line3->Changed) {
		EmptyOut(page->Line3->Centered ? Center(page->Line3->Text) : 0, 6, page->Line3->LastLen, strlen(page->Line3->Text),
				page->Line3->Selected);
		OLED_ShowString(page->Line3->Centered ? Center(page->Line3->Text) : 0, 6, page->Line3->Selected, page->Line3->Text);
		page->Line3->Changed = 0;
		page->Line3->LastLen = strlen(page->Line3->Text);
		anychange++;
	}

//if (!anychange)
//HAL_Delay(200);
}

// 更新页面，包括处理消息和渲染
inline void UpdatePage(SimplePage *page) {
	if (page->BeforeUpdate != NULL)
		page->BeforeUpdate(page);
	if (page->PendingRawInput != NULL) {
		page->PendingRawInput();
		page->PendingRawInput = NULL;
	}
	if (page->PendingFunCall != NULL) {
		page->PendingFunCall(page->LastTriggered);
		page->PendingFunCall = NULL;
	}
	if (!page->SelfRender)
		RenderPage(page);
}

// 创建一个空标签
Label* EmptyLabel() {
	Label *l = _new_(Label);
	l->LinkTo = NULL;
	l->OnClick = NULL;
	l->Selected = false;
	l->Selectable = true;
	l->Changed = true;
	l->Centered = false;
	l->Text = "";
	return l;
}

// 创建一个空页
SimplePage* EmptyPage() {
	SimplePage *page = _new_(SimplePage);
	page->LastTriggered = NULL;
	page->PendingFunCall = NULL;
	page->PendingRawInput = NULL;
	page->BeforeUpdate = NULL;
	page->InputHandler = NULL;
	page->SelectedIndex = 1;
	page->Title = "";
	page->Prev = NULL;
	page->Changed = true;
	page->SelfRender = false;

	page->Line1 = EmptyLabel();
	page->Line2 = EmptyLabel();
	page->Line3 = EmptyLabel();
	_SIMPLEPAGE_PGSync(page);

	return page;
}

//内部函数，将SelectedIndex数据赋予每个Label
inline void _SIMPLEPAGE_PGSync(SimplePage *page) {
	page->Line1->Selected = 0;
	page->Line2->Selected = 0;
	page->Line3->Selected = 0;
	if ((page->Line1->Selectable | page->Line2->Selectable
			| page->Line3->Selectable))
		switch (page->SelectedIndex) {
		case 1:
			if (page->Line1->Selectable)
				page->Line1->Selected = 1;
			else
				MenuSelectNext(page);
			break;
		case 2:
			if (page->Line2->Selectable)
				page->Line2->Selected = 1;
			else
				MenuSelectNext(page);
			break;
		case 3:
			if (page->Line3->Selectable)
				page->Line3->Selected = 1;
			else
				MenuSelectNext(page);
			break;
		}
}

inline void _SIMPLEPAGE_PGSync_rc(SimplePage *page, int dir) {
	page->Line1->Selected = 0;
	page->Line2->Selected = 0;
	page->Line3->Selected = 0;
	page->Line1->Changed = 1;
	page->Line2->Changed = 1;
	page->Line3->Changed = 1;
	if ((page->Line1->Selectable | page->Line2->Selectable
			| page->Line3->Selectable))
		switch (page->SelectedIndex) {
		case 1:
			if (page->Line1->Selectable) {
				page->Line1->Selected = true;
			} else if (dir)
				MenuSelectNext(page);
			else
				MenuSelectPrev(page);
			break;
		case 2:
			if (page->Line2->Selectable) {
				page->Line2->Selected = true;
			} else if (dir)
				MenuSelectNext(page);
			else
				MenuSelectPrev(page);
			break;
		case 3:
			if (page->Line3->Selectable) {
				page->Line3->Selected = true;
			} else if (dir)
				MenuSelectNext(page);
			else
				MenuSelectPrev(page);
			break;
		default:
			page->Line1->Selected = false;
			page->Line2->Selected = false;
			page->Line3->Selected = false;
			break;
		}
}

//菜单向下选择一项
inline void MenuSelectNext(SimplePage *page) {
	page->SelectedIndex++;
	if (page->SelectedIndex > 3)
		page->SelectedIndex = 1;
	_SIMPLEPAGE_PGSync_rc(page, 1);
//page->Changed = 1;
}

//菜单向上选择一项
inline void MenuSelectPrev(SimplePage *page) {
	page->SelectedIndex--;
	if (page->SelectedIndex < 1)
		page->SelectedIndex = 3;
	_SIMPLEPAGE_PGSync_rc(page, 0);
//page->Changed = 1;
}

//点击当前选中项
inline void MenuClick(SimplePage *page) {
	switch (page->SelectedIndex) {
	case 1:
		page->LastTriggered = page->Line1;
		if (page->Line1->OnClick != NULL)
			page->PendingFunCall = page->Line1->OnClick;
		break;
	case 2:
		page->LastTriggered = page->Line2;
		if (page->Line2->OnClick != NULL)
			page->PendingFunCall = page->Line2->OnClick;
		break;
	case 3:
		page->LastTriggered = page->Line3;
		if (page->Line3->OnClick != NULL)
			page->PendingFunCall = page->Line3->OnClick;
		break;
	}
}
