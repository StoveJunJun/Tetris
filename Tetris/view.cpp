#include "view.h"
#include "control.h"
#include <time.h>
#include<windows.h>
int DrawGame()
{
	system("cls");
	CombinOrDetachBg('\1');
	DrawBackGround();
	//DrawNext();

	CombinOrDetachBg('\0');
	return 1;
}

int DrawBackGround()
{
	int Row = 0;
	int Col = 0;
	for (; Row < GAME_ROW; Row++)
	{
		for (Col=0; Col < GAME_COL; Col++)
		{

			
			if (g_chBackGround[Row][Col] == 1)
			{
				printf("¡ö");
			}
			else
			{
				printf("¡õ");
			}
			if ((Row==0)&&(Col== (GAME_COL-1)))
			{
				/*printf("\t\t\t hi");*/
				DrawScore();
			}
		}
		printf("\r\n");
	}
	return 1;
}
int DrawBrick()
{
	int Row = 0;
	int Col = 0;
	for ( ; Row < 4; Row++)
	{
		for (Col = 0; Col < 4; Col++)
		{
			if (g_BrickCur[Row][Col] == 1)
			{
				printf("¡ö");
			}
			else
			{
				printf("¡õ");
			}
		}
		printf("\r\n");
	}
	return 1;
}
int DrawScore()
{
	//char LineAry[GAME_COL*2] = { 0 };
	//for (size_t i = 0; i < GAME_COL*2; i++)
	//{
	//	LineAry[i] = '=';
	//	printf("%c", LineAry[i]);
	//}
	//printf("\t\n");
	printf("\tyour score: \t%d", score);
	return 1;
	
}
int DrawNext()
{
	DrawBrick();
	return 2;
}

int OnDown()
{
	if (IsCanMove(g_nRow+1,g_nCol))
	{
		MoveDown();
		DrawGame();
	}
	else if(IsFullLine())
	{
		RemoveLine();
		DrawGame();
	}
	else
	{
		CombinOrDetachBg('\1');
		CreateNewBrick();
	}
return 1;
}

int OnRight()
{
	if (IsCanMove(g_nRow , g_nCol+1))
	{
		MoveRight();
		DrawGame();

	}
	return 1;
}

int OnLeft()
{
	if (IsCanMove(g_nRow, g_nCol-1))
	{
		MoveLeft();
		DrawGame();
	}
	return 1;
}

int OnUp()
{
	if (IsCanRotate())
	{
		Rotate();
		DrawGame();
	}
	return 1;
}

int  RemoveLine()
{
	int Row = 0;
	int Col = 0;
	for (Row = GAME_ROW-1; Row > 0; Row--)
	{
		for (Col = 1; Col < GAME_COL-1; Col++)
		{
			g_chBackGround[Row][Col] = g_chBackGround[Row - 1][Col];
		}
	}
	return 1;
}


