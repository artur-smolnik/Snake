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

enum GameMode
{
	EASY, NORMAL, HARD
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
	GameMode gameMode;
	Directions direction;
	Field board[100][100];
	int rows, columns;
	void setBoard();
	void setStartingPosition();
	void setHeadPosition();


public:
	Board(int rows, int columns, GameMode gameMode);	
	int getRows() { return rows; }
	int getColumns() { return columns; }
	bool hasSnake(int rows, int columns) { return board[rows][columns].hasSnake; }
	bool hasFood(int rows, int columns) { return board[rows][columns].hasFood; }

	void setDirection(int move);
};

