#include "pch.h"
#include "Board.h"


Board::Board(int rows, int columns, GameMode gameMode)
{
	this->rows = rows;
	this->columns = columns;
	this->gameMode = NORMAL;
	setBoard();
}

void Board::setDirection(int move)
{
	//int UP = 72, DOWN = 80, ENTER = 13, LEFT = 75, RIGHT = 77;

	switch (move)
	{
	case 72: 
		direction = NORTH;
		break;
	case  77:
		direction = EAST;
		break;
	case 80:
		direction = SOUTH;
		break;
	case 75:
		direction = WEST;
		break;
	default:
		break;
	}
}

void Board::setBoard()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			board[i][j].hasSnake = false;
			board[i][j].hasFood = false;
		}
	}
}

void Board::setStartingPosition()
{
	headPosition.row = rand() % rows + 4;
	headPosition.col = rand() % columns + 4;	
	
	board[headPosition.row][headPosition.col].hasSnake = true;
	board[headPosition.row + 1][headPosition.col].hasSnake = true;
	board[headPosition.row + 2][headPosition.col].hasSnake = true;

	snakePosition.push_front(headPosition);
	headPosition.row += 1;
	headPosition.col -= 1;
}

void Board::setHeadPosition()
{
	if (direction == NORTH)
	{
		if (headPosition.row - 1 < 0) headPosition.row = rows - 1;
		else headPosition.row -= 1;
	}
	else if (direction == EAST)
	{
		if (headPosition.col + 1 >= columns) headPosition.col = 0;
		else headPosition.col += 1;
	}
	else if (direction == SOUTH)
	{
		if (headPosition.row + 1 >= rows) headPosition.row = 0;
		else headPosition.row += 1;
	}
	else  if (direction == WEST)
	{
		if (headPosition.col - 1 < 0) headPosition.col = columns - 1;
		else headPosition.col -= 1;
	}
}


