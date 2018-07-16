#ifndef _VIEW_H
#define _VIEW_H

extern int score;
//extern HANDLE hOutput;
//extern COORD coord;
//extern HANDLE hOutBuf;
//extern CONSOLE_CURSOR_INFO cci;
//extern DWORD bytes = 0;
//extern char data[800];


int DrawBackGround();
int DrawScore();
int DrawBrick();

int DrawNext();
int DrawGame();
int OnDown();
int OnLeft();
int OnRight();
int OnUp();

int  RemoveLine();
#endif // !_VIEW_H

