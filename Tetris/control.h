#ifndef _CONTROL_H
#define _CONTROL_H
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


#define GAME_ROW 24
#define GAME_COL 16

extern char g_chBackGround[GAME_ROW][GAME_COL];
extern char g_chAllBricks[][4];
extern char g_BrickCur[4][4];
extern int g_nRow;
extern int g_nCol;

int InitBackGround();
int CreateNewBrick();
int CombinOrDetachBg(char chFlag);

int IsCanMove(int nRow, int nCol);
int IsCanRotate();
int IsFullLine();
int IsGameOver(int nRow, int nCol);


int MoveLeft();
int MoveRight();
int MoveDown();
int Rotate();




#endif // _CONTROL_H

