//Tetris.cpp: 定义控制台应用程序的入口点。
#include "control.h"
#include "view.h"
#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>


int InitGame()
{
	printf("Welcome to Tetris!!!!");
	InitBackGround();
	CreateNewBrick();
	DrawGame();
	return 1;
}

int   PrintGameOver()
{
	system("cls");
	printf("your score is :%d \n",score);
	printf("please enter q to quit:\r\n");
	while (1)
	{
		char QuitFlag;
		QuitFlag = _getch();
		if (QuitFlag=='q'||'Q')
		{
			return 0;
		}
	}

}

int main(int argc,const char *argv[])
{
	//HANDLE hOutput;
	//COORD coord = { 0,0 };
	//hOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	////创建新的缓冲区
	//HANDLE hOutBuf = CreateConsoleScreenBuffer(
	//	GENERIC_READ | GENERIC_WRITE,
	//	FILE_SHARE_READ | FILE_SHARE_WRITE,
	//	NULL,
	//	CONSOLE_TEXTMODE_BUFFER,
	//	NULL
	//);

	////设置新的缓冲区为活动显示缓冲
	//SetConsoleActiveScreenBuffer(hOutBuf);

	////隐藏两个缓冲区的光标
	//CONSOLE_CURSOR_INFO cci;
	//cci.bVisible = 0;
	//cci.dwSize = 1;
	//SetConsoleCursorInfo(hOutput, &cci);
	//SetConsoleCursorInfo(hOutBuf, &cci);

	////双缓冲处理显示
	//DWORD bytes = 0;
	//char data[800];

	InitGame();
	char chControl = '\0';
	clock_t start = clock();

	while (!IsGameOver(g_nRow,g_nCol))
	{
		clock_t finish = clock()-start;
		if (finish>500)
		{
			OnDown();
			start = finish + start;
		}
		if (_kbhit() != 0)
		{
			chControl = _getch();
		}
		switch (chControl)
		{
		case 'w' :
			OnUp();
			break;
		case 's':
			OnDown();
			break;
		case 'a':
			OnLeft();
			break;
		case 'd':
			OnRight();
			break;

		default:
			break;
		}
		chControl = '\0';
	}
	PrintGameOver();
}

