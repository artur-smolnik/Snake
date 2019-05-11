#include "pch.h"
#include "SFML/Graphics.hpp"
#include "BoardController.h"
#include <conio.h>
#include <stdlib.h>




BoardController::BoardController(BoardView &boardView, Board &board) : boardView(boardView), board(board)
{
}

void BoardController::draw(sf::RenderWindow &renderWindow)
{
	boardView.draw(renderWindow);
}

void BoardController::handleKeyboard(sf::Event &event)
{
	
		if (event.type == sf::Event::KeyPressed) 
		{
			if (event.key.code == sf::Keyboard::Up && board.getDirection() != SOUTH) 
			{
				board.setDirection(NORTH);
			}
			else if (event.key.code == sf::Keyboard::Right && board.getDirection() != WEST)
			{
				board.setDirection(EAST);

			}
			else if (event.key.code == sf::Keyboard::Down && board.getDirection() != NORTH)
			{
				board.setDirection(SOUTH);

			}
			else if (event.key.code == sf::Keyboard::Left && board.getDirection() != EAST)
			{
				board.setDirection(WEST);
			}
		}
}

void BoardController::handleEvent(sf::Event &event)
{
	handleKeyboard(event);
	board.setHeadPosition();
	if(!board.detectCollision())  board.setNewSnakePosition();
	
}

