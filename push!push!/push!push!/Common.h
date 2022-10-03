#pragma once

#include <conio.h>
#include <iostream>
#include <Windows.h>


#include <string>
#include <vector>
#include <list>

#include "yaMath.h"

#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

#define GOTO_XY(x, y) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{(short)x, (short)y})
#define SET_COLOR(color) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color)

enum COLOR
{
	BLACK, /* 0 : 까망 */
	DARK_BLUE, /* 1 : 어두운 파랑 */
	DARK_GREEN, /* 2 : 어두운 초록 */
	DARK_SKY_BLUE, /* 3 : 어두운 하늘 */
	DARK_RED, /* 4 : 어두운 빨강 */
	DARK_VIOLET, /* 5 : 어두운 보라 */
	DARK_YELLOW, /* 6 : 어두운 노랑 */
	GRAY, /* 7 : 회색 */
	DARK_GRAY, /* 8 : 어두운 회색 */
	BLUE, /* 9 : 파랑 */
	GREEN, /* 10 : 초록 */
	SKY_BLUE, /* 11 : 하늘 */
	RED, /* 12 : 빨강 */
	VIOLET, /* 13 : 보라 */
	YELLOW, /* 14 : 노랑 */
	WHITE, /* 15 : 하양 */
};


class Pen
{
public:
	Pen(wchar_t ch)
	{
		mColor = COLOR::DARK_SKY_BLUE;
		SET_COLOR(mColor);
		std::wcout << ch;
	}

	Pen(WORD color, wchar_t ch)
	{
		mColor = color;
		SET_COLOR(mColor);
		std::wcout << ch;
	}

	~Pen()
	{
		mColor = COLOR::DARK_SKY_BLUE;
		SET_COLOR(mColor);
	}

private:
	WORD mColor;

};