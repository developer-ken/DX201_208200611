#include "main.h"
const u8 HMQR[]={
		0x00,0x00,0x00,0x00,0x00,0xE0,0xE0,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,
		0x60,0x60,0x60,0x60,0xE0,0xE0,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xE0,
		0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xE0,0xE0,0x60,0x60,0x60,0x60,0x60,
		0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0xE0,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,
		0xFC,0x00,0x00,0x00,0xFF,0xFF,0xFF,0x00,0x00,0x0C,0x0C,0x0C,0x7C,0x7C,0x7F,0x7F,
		0x7F,0x0C,0x0C,0x0C,0x0C,0x0C,0x00,0x00,0xFF,0xFF,0xFF,0x00,0x00,0x00,0xFC,0xFC,
		0xFC,0xFC,0xFC,0xFC,0xFC,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x7F,0x7F,0x70,0x70,0x70,0x71,0x71,0x71,0x71,0x71,0x71,
		0x71,0x70,0x70,0x70,0x7F,0x7F,0x7F,0x00,0x00,0xF0,0xF0,0xF0,0x8E,0x8E,0x70,0x70,
		0x70,0x80,0x80,0x70,0x70,0x70,0x00,0x00,0x7F,0x7F,0x7F,0x70,0x70,0x70,0x71,0x71,
		0x71,0x71,0x71,0x71,0x71,0x70,0x70,0x70,0x7F,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0xFE,0xFE,0xFE,0xFE,0xFE,0x3E,0x3E,0xF0,0xF0,0xF0,0x3E,
		0x3E,0xCE,0xCE,0xCE,0xCE,0xCE,0xCE,0xCE,0xCE,0xCF,0xCF,0xCF,0x01,0x01,0xCE,0xCE,
		0xCE,0xCF,0xCF,0xFE,0xFE,0xFE,0xCE,0xCE,0x3E,0x3E,0x3E,0x30,0x30,0x30,0xF0,0xF0,
		0x00,0x00,0x00,0xCE,0xCE,0xC0,0xC0,0xC0,0xF0,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x39,0x39,0x39,0x00,0x00,0x3F,0x3F,0x3F,0x38,
		0x38,0x07,0x07,0x07,0x39,0x39,0x39,0x3F,0x3F,0xF9,0xF9,0xF9,0xC6,0xC6,0xFF,0xFF,
		0xFF,0xFF,0xFF,0xC7,0xC7,0xC7,0x01,0x01,0xC0,0xC0,0xC0,0xF8,0xF8,0xF8,0xC7,0xC7,
		0x38,0x38,0x38,0x01,0x01,0xC7,0xC7,0xC7,0xC1,0xC1,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x07,0x07,0x07,0xC7,0xC7,0xC7,0xC7,0xC7,0xC7,
		0xC7,0x07,0x07,0x07,0xFF,0xFF,0xFF,0x00,0x00,0xFF,0xFF,0xFF,0x3F,0x3F,0x3F,0x3F,
		0x3F,0x38,0x38,0xC7,0xC7,0xC7,0xC7,0xC7,0x07,0x07,0x07,0x38,0x38,0x38,0x3F,0x3F,
		0xC0,0xC0,0xC0,0x07,0x07,0x07,0x07,0x07,0xC7,0xC7,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,
		0x1F,0x00,0x00,0x00,0xFF,0xFF,0xFF,0x00,0x00,0xF8,0xF8,0xF8,0x18,0x18,0x18,0x18,
		0x18,0x18,0x18,0xFF,0xFF,0xFF,0x1F,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,
		0x07,0x07,0x07,0x18,0x18,0xE0,0xE0,0xE0,0x18,0x18,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,
		0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x00,0x00,0x03,0x03,0x03,0x00,0x00,0x00,0x00,
		0x00,0x03,0x03,0x03,0x03,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x03,
		0x03,0x03,0x03,0x00,0x00,0x03,0x03,0x03,0x03,0x03,0x00,0x00,0x00,0x00,0x00,0x00
};
/* 64*64 ,msgp.tech*/


const u8 GHQR[]={
		0x00,0x00,0x00,0x00,0xF0,0xF0,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,
		0x30,0xF0,0xF0,0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x30,0x30,0xF0,0xF0,0xC0,0xC0,
		0xC0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xC0,0xC0,0x00,0x00,0x00,0xF0,0xF0,0x30,0x30,
		0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0xF0,0xF0,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x00,
		0x00,0xFF,0xFF,0x00,0x00,0x00,0x07,0x07,0x80,0x80,0xF8,0xF8,0xE0,0xE0,0x60,0x60,
		0x60,0x60,0x60,0xE0,0xE0,0xE7,0xE7,0x80,0x80,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,
		0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0xC7,0xC7,0xC6,0xC6,0xC6,0xC6,0xC6,0x06,0x06,0xC6,0xC6,0xC6,
		0xC6,0xC7,0xC7,0xC0,0xC0,0xC0,0xFE,0xFE,0xF9,0xF9,0x3F,0x3F,0x01,0x01,0x06,0x06,
		0x06,0xF8,0xF8,0x3F,0x3F,0x01,0x01,0xC7,0xC7,0xC0,0xC0,0xC0,0xC7,0xC7,0x06,0x06,
		0x06,0x06,0x06,0x06,0xC6,0xC6,0xC6,0x06,0x06,0x07,0x07,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x03,0x03,0xF3,0xF3,0xCF,0xCF,0xCF,0x00,0x00,0x03,0x03,0x00,
		0x00,0xCC,0xCC,0x3F,0x3F,0x3F,0x33,0x33,0x3C,0x3C,0xC0,0xC0,0x30,0x30,0xF3,0xF3,
		0xF3,0xF3,0xF3,0x00,0x00,0xC0,0xC0,0xFF,0xFF,0xC3,0xC3,0xC3,0xC3,0xC3,0x0C,0x0C,
		0x00,0x00,0xC0,0xC0,0x0C,0x0C,0x0C,0xFC,0xFC,0xCF,0xCF,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x98,0x98,0x61,0x61,0xE1,0xE1,0xE1,0x78,0x78,0x06,0x06,0x86,
		0x86,0x99,0x99,0xE0,0xE0,0xE0,0x86,0x86,0x06,0x06,0x79,0x79,0x60,0x60,0x1F,0x1F,
		0x1F,0xE7,0xE7,0x60,0x60,0x01,0x01,0x99,0x99,0xF9,0xF9,0xF9,0x9F,0x9F,0x98,0x98,
		0xE0,0xE0,0x87,0x87,0x18,0x18,0x18,0x79,0x79,0x1F,0x1F,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0xF1,0xF1,0x30,0x30,0x31,0x31,0x31,0x30,0x30,0x30,0x30,0x31,
		0x31,0xF1,0xF1,0x01,0x01,0x01,0xFF,0xFF,0xCE,0xCE,0x0E,0x0E,0x00,0x00,0xCE,0xCE,
		0xCE,0xFF,0xFF,0x0E,0x0E,0x3E,0x3E,0xFF,0xFF,0x01,0x01,0x01,0x31,0x31,0x01,0x01,
		0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0xFE,0xFE,0x3E,0x3E,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x00,
		0x00,0xFF,0xFF,0x00,0x00,0x00,0xF3,0xF3,0x70,0x70,0x80,0x80,0x83,0x83,0xFF,0xFF,
		0xFF,0x8F,0x8F,0x80,0x80,0x70,0x70,0xF3,0xF3,0x83,0x83,0x83,0x83,0x83,0x0F,0x0F,
		0xFF,0xFF,0x8F,0x8F,0x0C,0x0C,0x0C,0x8C,0x8C,0x7F,0x7F,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x07,0x07,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,
		0x06,0x07,0x07,0x00,0x00,0x00,0x07,0x07,0x00,0x00,0x07,0x07,0x07,0x07,0x07,0x07,
		0x07,0x07,0x07,0x01,0x01,0x06,0x06,0x07,0x07,0x01,0x01,0x01,0x07,0x07,0x06,0x06,
		0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x07,0x07,0x06,0x06,0x00,0x00,0x00,0x00,0x00
};
/* 64*64 ,github.com/developer_ken */

const u8 BMAVATAR[] = {
		0xEF,0xFF,0x7F,0x0F,0xB3,0xFE,0xFF,0xFF,0xFF,0xF9,0xFE,0xCF,0xFF,0xFF,0xFF,0xFF,
		0x7F,0xFF,0xFF,0x57,0xFF,0xFF,0xFF,0xFF,0xF7,0xFF,0x37,0xBB,0xBB,0xDD,0xCF,0x6F,
		0xF7,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x1F,0xFF,0xF9,0xF8,0xF8,0xE1,0x87,0x1F,0xFF,
		0xFF,0xFF,0xFF,0xFF,0xDF,0xE7,0x0F,0x7F,0xFF,0xFF,0xFF,0xDF,0xFF,0xFF,0xFF,0xFF,
		0xFF,0xFF,0xFC,0x7F,0x1F,0xFF,0xFF,0xFF,0xFF,0xFB,0xF7,0xFF,0xFF,0xDF,0xF7,0xFD,
		0x7F,0x3F,0x3F,0x88,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0x9F,0xB9,0xDE,
		0xEF,0xFF,0xFD,0x3F,0x8F,0xE7,0xF9,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xFD,
		0xC3,0x00,0x4F,0xFF,0xFF,0xFD,0xF8,0xF8,0xFF,0xFF,0xFF,0x7F,0xFF,0xFF,0xFF,0xFF,
		0x3F,0xFF,0xFF,0xFC,0x07,0xFF,0xFF,0xFF,0xFF,0x3F,0x9F,0xBB,0xBB,0xBF,0xB3,0xB8,
		0x3C,0x3E,0x7B,0x7B,0xFF,0xF7,0xFB,0xFF,0x39,0xFF,0xCF,0x0F,0x01,0xFE,0xFF,0xFF,
		0xFF,0xFB,0xE6,0xF7,0xF7,0xFF,0xFF,0xFF,0x7B,0x7F,0x7F,0x7F,0x7F,0x7F,0x5F,0x78,
		0x7F,0x7F,0xF4,0x80,0xFF,0xFF,0x1F,0xFB,0xFF,0x1F,0x20,0x7F,0xFF,0x0F,0xBF,0xFD,
		0x90,0x78,0x3F,0x03,0xCF,0x7F,0xF3,0xFD,0xD9,0x67,0xFF,0xFF,0xFF,0xFF,0xFF,0xDC,
		0xFE,0xFF,0xFE,0xF6,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xBC,0xFB,0xFF,0xFF,
		0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xFF,0xFC,0xFE,0xFE,0xDE,0xDE,0xED,0xF9,0xFF,
		0xFF,0xF6,0xF8,0x7C,0x97,0xC7,0xF3,0xF9,0xFE,0xFF,0xFF,0xFF,0xF8,0xE3,0xCF,0x1F,
		0xF3,0xE1,0xE0,0xE3,0xE1,0xC0,0xC0,0xC3,0xCF,0x8E,0x0F,0x7F,0xFF,0xFF,0xFF,0xFF,
		0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFB,0xFF,0xFF,
		0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
		0xFF,0xFF,0x7D,0x7E,0xFF,0xF7,0x7B,0x7F,0x3F,0x3F,0x1F,0x0F,0x87,0x83,0xC0,0xE0,
		0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF8,0xC1,0xC7,0xCF,0xDF,
		0xBF,0xFF,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF7,0xF3,0xF3,0xFB,0xFB,0xE7,0xE7,
		0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0xFF,0xFF,0x3F,0x0F,0x87,
		0xE3,0xF1,0xF8,0xFE,0xF8,0xFE,0xFE,0xFC,0xFC,0xFC,0xF8,0xF8,0xF9,0xF9,0xF9,0xF1,
		0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
		0x1F,0x09,0xF0,0xC0,0x01,0x83,0xE3,0xF7,0xF7,0xCF,0x9F,0x9F,0x1F,0x1F,0x9F,0x9F,
		0xCF,0xCF,0xEF,0xF7,0xF7,0xFB,0xFB,0xFD,0xFC,0xFE,0xFF,0xFF,0xE3,0xF8,0x13,0x3F,
		0x3F,0x7F,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
		0xFC,0xFC,0xFC,0xFE,0xFE,0xFF,0xFF,0x7F,0x3F,0x1F,0x8F,0xE7,0xE3,0xF1,0xFC,0x0F,
		0x38,0x70,0xF9,0xFF,0xCF,0xEC,0x67,0x7F,0x7F,0x7F,0x7F,0x7F,0xFF,0xFF,0xFF,0x7F,
		0x7F,0x7F,0xFF,0xBF,0x1F,0xEF,0xFF,0xEB,0xFB,0xF7,0xFB,0xFD,0xFF,0xEF,0xF0,0xFC,
		0xDE,0xFF,0xFF,0x0C,0x01,0xFF,0xFF,0xFF,0xF3,0xF3,0xE7,0xEF,0xDF,0xFF,0xFF,0xFF
};
/* 64*64 Avarta */

const u8 SPLASHBM[] = {
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,
		0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x40,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x80,0x80,
		0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,0xC0,0x80,0x80,
		0x80,0x80,0xC0,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,
		0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0x86,0x01,0x00,0x00,0x00,
		0x00,0x00,0x01,0x86,0xFC,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0xFF,0x10,0x10,0x10,0x10,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x01,0x01,
		0x86,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x48,0x44,0x24,0x22,0x25,0x99,0x51,
		0x49,0x69,0x65,0x45,0x43,0xC1,0x40,0x00,0x00,0x6C,0x79,0x48,0x44,0x42,0x80,0xFF,
		0x18,0x60,0x80,0x8C,0xCB,0x38,0x00,0x00,0x00,0x84,0x84,0xB4,0x84,0x85,0x84,0xD4,
		0x94,0x84,0x85,0xA4,0x94,0x84,0x80,0x00,0x00,0x00,0xFE,0x4A,0x4A,0x4B,0x4A,0xFE,
		0x4A,0x4A,0x4B,0x4A,0x4A,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x02,0x04,0x04,0x04,
		0x04,0x04,0x02,0x01,0x00,0x00,0x00,0x00,0x07,0x04,0x04,0x04,0x04,0x04,0x00,0x00,
		0x07,0x04,0x04,0x04,0x04,0x04,0x00,0x00,0x00,0x07,0x04,0x04,0x04,0x04,0x06,0x02,
		0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x12,0x11,0x11,0x08,0x08,0x0B,
		0x04,0x04,0x02,0x02,0x01,0x00,0x00,0x00,0x02,0x02,0x01,0x01,0x09,0x06,0x03,0x08,
		0x04,0x04,0x03,0x03,0x06,0x04,0x08,0x08,0x08,0x08,0x04,0x04,0x02,0x02,0x01,0x1F,
		0x01,0x01,0x02,0x04,0x04,0x08,0x08,0x08,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x1F,
		0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x08,0x08,0x08,0xB0,0xE0,0x00,0x00,0xE0,
		0x30,0x08,0x08,0x08,0x30,0xE0,0x00,0x00,0x60,0xF0,0x08,0x08,0x08,0xF0,0x60,0x00,
		0x00,0x00,0x18,0x08,0x08,0x08,0xB0,0xE0,0x00,0x00,0xE0,0x30,0x08,0x08,0x08,0x30,
		0xE0,0x00,0x00,0xE0,0x30,0x08,0x08,0x08,0x30,0xE0,0x00,0x00,0xC0,0x60,0x10,0x08,
		0x08,0x08,0x08,0x00,0x00,0x00,0x20,0x10,0xF0,0xF8,0x00,0x00,0x00,0x00,0x00,0x20,
		0x10,0xF0,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x58,0x4C,0x46,0x42,0x43,0x40,0x00,0x00,0x1F,
		0x30,0x40,0x40,0x40,0x30,0x1F,0x00,0x00,0x3C,0x22,0x41,0x41,0x41,0x62,0x3E,0x00,
		0x00,0x70,0x58,0x4C,0x46,0x42,0x43,0x40,0x00,0x00,0x1F,0x30,0x40,0x40,0x40,0x30,
		0x1F,0x00,0x00,0x1F,0x30,0x40,0x40,0x40,0x30,0x1F,0x00,0x00,0x1F,0x32,0x41,0x41,
		0x41,0x63,0x3E,0x00,0x00,0x00,0x00,0x00,0x7F,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x7F,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x90,0x10,0x10,0x10,0xF0,0x10,0x00,0x00,
		0xF0,0x10,0x10,0x10,0xD0,0x30,0x00,0x80,0x80,0x90,0x90,0x90,0xF0,0x90,0x90,0x90,
		0x90,0x90,0x90,0x90,0xF0,0x80,0x80,0x00,0x00,0x00,0x80,0x80,0x80,0x80,0xF0,0xA0,
		0xA0,0xA0,0xA0,0xA0,0x20,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x81,0x43,0x3C,0x1C,0x63,0xC0,0x00,0x00,
		0xFF,0x00,0x80,0x83,0x84,0x78,0x00,0x80,0xC4,0x64,0x34,0xFC,0x27,0x24,0x24,0x24,
		0x24,0x24,0x24,0x24,0xEF,0x00,0x00,0x00,0x80,0x80,0xBF,0x92,0x92,0x92,0xF2,0x92,
		0x92,0x92,0x92,0xBF,0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x01,0x01,0x01,0x01,
		0x01,0x01,0x01,0x01,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};
/* 128*64 Splash Screen */
