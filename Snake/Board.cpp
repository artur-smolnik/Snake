#include "pch.h"
#include "Board.h"
#include <Windows.h>


Board::Board(int rows, int columns)
{
	this->rows = rows;
	this->columns = columns;
	setBoard();
	setStartingPosition();
	direction = SOUTH;
	setFoodOnBoard();
	finished = false;

}

void Board::playAgain()
{
	snakePosition.clear();
	setBoard();
	setStartingPosition();
	direction = SOUTH;
	finished = false;
	setFoodOnBoard();
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
	headPosition.row = 0;
	headPosition.col = 0;
	
	board[headPosition.row][headPosition.col].hasSnake = true;
	board[headPosition.row + 1][headPosition.col].hasSnake = true;
	board[headPosition.row + 2][headPosition.col].hasSnake = true;

	snakePosition.push_front(headPosition);
	headPosition.row += 1;	
	snakePosition.push_front(headPosition);
	headPosition.row += 1;	
	snakePosition.push_front(headPosition);
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


void Board::setNewSnakePosition()
{	
	
	if (isFoodEaten())
	{
		if (detectCollision())
		{
			finished = true;
			return;
		}
		board[headPosition.row][headPosition.col].hasSnake = true;
		snakePosition.push_front(headPosition);
		board[headPosition.row][headPosition.col].hasFood = false;
		setFoodOnBoard();
	}
	else
	{
		if (detectCollision())
		{
			finished = true;
			return;
		}
		board[snakePosition.back().row][snakePosition.back().col].hasSnake = false;
		snakePosition.pop_back();
		board[headPosition.row][headPosition.col].hasSnake = true;
		snakePosition.push_front(headPosition);
	}	
}

void Board::setFoodOnBoard()
{
	int row, col;
	do
	{
		row = rand() % rows;
		col = rand() % columns;
		if (!board[row][col].hasSnake)
		{
			board[row][col].hasFood = true;
			
		}
	} while (!board[row][col].hasFood);
}

bool Board::isFoodEaten()
{
	if (board[headPosition.row][headPosition.col].hasFood) return true;
	else return false;
}

bool Board::detectCollision()
{
	if (board[headPosition.row][headPosition.col].hasSnake) return true;
	return false;
}


