#pragma once
#include <stdio.h>
#include <windows.h>

#define delta_time 0.001
#define SCREEN_WIDTH 100
#define SCREEN_HEIGHT 50

enum
{
	BLACK,
	DARK_BLUE,
	DARK_GREEN,
	DARK_SKYBLUE,
	DARK_RED,
	DARK_VOLET,
	DARK_YELLOW,
	GRAY,
	DARK_GRAY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	VIORET,
	YELLOW,
	WHITE
};
void SetColor(int color_number)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}

void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void print(int x, int y, char *str, int color)
{
	SetColor(color);
	gotoxy(x, y);
	printf("%s",str);
}
bool InWindow(int x, int y )
{
	if (x >= SCREEN_WIDTH)
		return false;
	if (y >= SCREEN_HEIGHT)
		return false;
	if (x <  1)
		return false;
	if (y <  1)
		return false;
	return true;
}
void RemoveCursor()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
void Render_Init()
{
	system("mode con:cols=100 lines=50");
	RemoveCursor();
}


void Render(int retime)
{
	Sleep(retime);
	system("cls");
}