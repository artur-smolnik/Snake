#pragma once
#include "SFML/Graphics.hpp"
#include <list> 

struct Field
{
	bool hasSnake;
	bool hasFood;		
};

enum Directions
{
	NORTH, EAST, SOUTH, WEST
};

class Board
{
	struct HeadPosition
	{
		int row;
		int col;
	};

	std::list<HeadPosition> snakePosition;
	HeadPosition headPosition;
	Directions direction;
	Field board[100][100];
	bool finished;

	int rows, columns;
	void setBoard();
	void setStartingPosition();
	void setFoodOnBoard();
	bool isFoodEaten();
	bool detectCollision();

public:
	Board(int rows, int columns);	
	int getRows() { return rows; }
	int getColumns() { return columns; }
	bool hasSnake(int rows, int columns) { return board[rows][columns].hasSnake; }
	bool hasFood(int rows, int columns) { return board[rows][columns].hasFood; }
	void setDirection(Directions dir) { direction = dir; }
	Directions getDirection() { return direction; }
	void setNewSnakePosition();
	void setHeadPosition();
	bool isFinished() { return finished; }
	int getSnakeLength() { return snakePosition.size(); }
	void playAgain();
	std::list<HeadPosition> &getSnakePosition() { return snakePosition; }
};

