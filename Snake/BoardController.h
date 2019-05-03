#pragma once
#include "BoardView.h"
#include "Board.h"
class BoardController
{
	BoardView &boardView;
	Board &board;
public:
	BoardController(BoardView &boardView, Board &board);
	void draw();
	void handleKeyboard();
	void handleEvent();
	
};

