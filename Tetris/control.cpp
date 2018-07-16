#include"control.h"
#include<stdio.h>
#include<time.h>
//������
char g_chBackGround[GAME_ROW][GAME_COL] = { 0 };
char g_chAllBricks[][4] = {
	//L��
	1,0,0,0,
	1,1,1,0,
	0,0,0,0,
	0,0,0,0,

	1,1,0,0,
	1,0,0,0,
	1,0,0,0,
	0,0,0,0,

	1,1,1,0,
	0,0,1,0,
	0,0,0,0,
	0,0,0,0,

	0,1,0,0,
	0,1,0,0,
	1,1,0,0,
	0,0,0,0,

	//I��
	1,1,1,1,
	0,0,0,0,
	0,0,0,0,
	0,0,0,0,

	1,0,0,0,
	1,0,0,0,
	1,0,0,0,
	1,0,0,0,

	1,1,1,1,
	0,0,0,0,
	0,0,0,0,
	0,0,0,0,

	1,0,0,0,
	1,0,0,0,
	1,0,0,0,
	1,0,0,0,
	//Z��

	0,0,1,0,
	0,1,1,0,
	0,1,0,0,
	0,0,0,0,

	0,1,1,0,
	0,0,1,1,
	0,0,0,0,
	0,0,0,0,

	0,1,0,0,
	0,1,1,0,
	0,0,1,0,
	0,0,0,0,

	0,1,1,0,
	1,1,0,0,
	0,0,0,0,
	0,0,0,0,

	//͹��
	0,1,0,0,
	1,1,1,0,
	0,0,0,0,
	0,0,0,0,

	0,1,0,0,
	1,1,0,0,
	0,1,0,0,
	0,0,0,0,

	0,0,0,0,
	1,1,1,0,
	0,1,0,0,
	0,0,0,0,

	0,1,0,0,
	0,1,1,0,
	0,1,0,0,
	0,0,0,0,

	//��
	0,0,0,0,
	0,1,1,0,
	0,1,1,0,
	0,0,0,0,

	0,0,0,0,
	0,1,1,0,
	0,1,1,0,
	0,0,0,0,

	0,0,0,0,
	0,1,1,0,
	0,1,1,0,
	0,0,0,0,

	0,0,0,0,
	0,1,1,0,
	0,1,1,0,
	0,0,0,0,
};
char g_BrickCur[4][4] = { 0 };
int score = 0;

//����
int g_nRow = 0;
int g_nCol = 0;
int g_nType = 0;
int g_nRotate = 0;
int InitBackGround()
{
	int Row = 0;
	int Col = 0;
	for (; Row < GAME_ROW; Row++)
	{
		for (Col=0 ; Col < GAME_COL; Col++)
		{
			if (Row == GAME_ROW - 1 || Col == 0 || Col== GAME_COL - 1)//�����߽�
			{
				g_chBackGround[Row][Col] = 1;
			}
			else
			{
				g_chBackGround[Row][Col] = 0;
			}
		}
	}
	return 1;
}

int CreateNewBrick()
{
	int Row = 0;
	int Col = 0;
	int nSumType = (sizeof(g_chAllBricks) / sizeof(g_chAllBricks[0])) / 16;

	srand((unsigned)time(NULL));
	g_nType = rand() % nSumType;
	g_nRotate = rand() % 4;
	g_nRow = 0;
	g_nCol = GAME_COL / 2;

	for (size_t Row = 0; Row < 4; Row++)
	{
		for (size_t Col = 0; Col < 4; Col++)
		{
			g_BrickCur[Row][Col] = g_chAllBricks[Row + 16 * g_nType + 4 * g_nRotate][Col];
		}
	}
	return 1;
}

int CombinOrDetachBg(char chFlag)
{
	int Row = 0;
	int Col = 0;
	for (size_t Row = 0; Row < 4; Row++)
	{
		for (size_t Col = 0; Col < 4; Col++)
		{
			if (g_BrickCur[Row][Col]==1)
			{
				g_chBackGround[Row + g_nRow][Col + g_nCol] \
					= chFlag;
			}
		}
	}
	return 1;
}

//�߽���
int IsCanMove(int nRow, int nCol)
{
	int Row = 0;
	int Col = 0;
	for (size_t Row = 0; Row < 4; Row++)
	{
		for (size_t Col = 0; Col < 4; Col++)
		{
			if (g_BrickCur[Row][Col]==1)
			{
				if (g_chBackGround[Row+nRow][Col+nCol] == 1)
				{
					return 0;
				}
			}
		}
	}
	return 1;
}
//����
int MoveLeft()
{
	g_nCol--;
	return 1;
}

int MoveRight()
{
	g_nCol++;
	return 1;
}

int MoveDown()
{
	g_nRow++;
	return 1;
}
//�ж�
int Rotate()
{
	int Row = 0;
	int Col = 0;
	int nSumType = (sizeof(g_chAllBricks) / sizeof(g_chAllBricks[0])) / 16;

	g_nRotate = (g_nRotate + 1) % 4;

	for (size_t Row = 0; Row < 4; Row++)
	{
		for (size_t Col = 0; Col < 4; Col++)
		{
			g_BrickCur[Row][Col] = g_chAllBricks[Row + 16 * g_nType + 4 * g_nRotate][Col];

		}
	}
	return 1;
}
int IsCanRotate()
{
	char chTempBrickAry[4][4] = { 0 };

	int Row = 0;
	int Col = 0;
	int nSumType = (sizeof(g_chAllBricks) / sizeof(g_chAllBricks[0])) / 16;

	int nNextRotate = 0;
	nNextRotate = (g_nRotate + 1) % 4;

	for (size_t Row = 0; Row < 4 ; Row++)
	{
		for (size_t Col = 0; Col < 4; Col++)
		{
			if (g_BrickCur[Row][Col]==1)
			{
				if (g_chBackGround[Row + g_nRow][Col + g_nCol] == 1)
				{
					return 1;
				}
			}
		}
	}

	return 1;
	
}

//���м��
int IsFullLine()
{
	int Row = 0;
	int Col = 0;
	int count = 0;
	for ( Row = GAME_ROW-2; Row >= 0; Row--)
	{
		for ( Col = 1; Col < GAME_COL; Col++)
		{
			if (g_chBackGround[Row][Col] != 1)
			{
				break;
			}
			else
			{
				count++;
				if (count==GAME_COL-2)
				{
					score += 10;
					return 1;
				}
			}
		}
		count = 0;
	}
	return 0;
}
//��Ϸ�������
int IsGameOver(int nRow, int nCol)
{
	int Row = 0;
	int Col = 0;
	for (size_t Row = 0; Row < 4; Row++)
	{
		for (size_t Col = 0; Col < 4; Col++)
		{
			if (g_BrickCur[Row][Col] == 1)
			{
				if (g_chBackGround[0+nRow][Col + nCol] == 1)
				{
					return 1;
				}
			}
		}
	}
	return 0;
}