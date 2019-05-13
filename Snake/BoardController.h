#pragma once
#include "BoardView.h"
#include "Board.h"
class BoardController
{
	BoardView &boardView;
	Board &board;
	
public:
	BoardController(BoardView &boardView, Board &board);
	void draw(sf::RenderWindow &renderWindow);
	void handleKeyboard(sf::Event &event);
	
	void handleEvent(sf::Event &event);
	//bool isFinished() { return finished; }
	bool isFinished();
	void playAgain() { board.playAgain(); }
	
};

