#pragma once
#include"common.h"
void menu();
void InitBoard(char board[ROW][COL], int row, int col);
void DisPlayBoard(char board[ROW][COL], int row, int col);
void game();

void menu()
{
	printf("***********************************************\n");
	printf("*************      1 .play     ****************\n");
	printf("*************      0 .exit     ****************\n");
	printf("***********************************************\n");
}


void InitBoard(char board[][COL], int row, int col)
{
	memset(&board[0][0], ' ', sizeof(board[0][0] * row*col));
}

void DisPlayBoard(char board[][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; ++i)
	{
		printf(" %c | %c | %c |\n" ,board[i][0],board[i][1],board[i][2]);
		if(i < row - 1)
		printf("--- --- --- ");
	}
}
/*
void ComputerMove(char board[ROW][COL],int row,int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走->");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[row][col] == ' ')
		{
			printf("X", board[row][col]);
			break;
		}
	}
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走->(输入坐标中间用逗号隔开)");
	while(1)
	{ 
	scanf("%d,%d", &x, &y);
	if (board[x][y] == ' ')
	{
		printf("O", board[x][y]);
		break;
	}
	else
		printf("您下棋的位置已被占用，请重新输入坐标");
}

/*void IsWin()
{
	if (board[])
		printf("电脑赢");
	if ()
		printf("玩家赢");
	

}*/ 