#include<stdio.h>
#include<stdlib.h>

#define ROW 3
#define COL 3

void Init(char arr[ROW][COL], int row, int col);
void Display(char arr[ROW][COL], int row, int col);
void PlayerMove(char arr[ROW][COL], int row, int col);
void ComputerMove(char arr[ROW][COL], int row, int col);
char IsWin(char arr[ROW][COL], int row, int col);