#include "pch.h"
#include "SFML/Graphics.hpp"
#include "BoardController.h"
#include <conio.h>
#include <stdlib.h>




BoardController::BoardController(BoardView &boardView, Board &board) : boardView(boardView), board(board)
{
}

void BoardController::draw()
{
	boardView.draw();
}

void BoardController::handleKeyboard()
{
	unsigned char selectedKey;
		
	do
	{
		selectedKey = _getch();			
		{	
			while (_kbhit())
			{
				selectedKey = _getch();
				board.setDirection(static_cast <int>(selectedKey));
			}
		}
	} while (selectedKey != 27); //ESC
}
