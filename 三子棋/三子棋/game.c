#include"game.h"

void game()
{
	printf("ÕÊ”Œœ∑");
	char board[ROW][COL] = { 0 };
	InitBoard(board[ROW][COL], ROW, COL);
	DisPlayBoard(board[ROW][COL], ROW, COL);
	while (1)
	{
		//ComputerMove(board[ROW][COL], ROW, COL);
		DisPlayBoard(board[ROW][COL], ROW, COL);
		//PlayerMove(board[ROW][COL], ROW, COL);
		//DisPlayBoard(board[ROW][COL], ROW, COL);
		//void IsWin();
	}
}