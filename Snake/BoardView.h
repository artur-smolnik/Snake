#pragma once
#include "SFML/Graphics.hpp"
#include "Board.h"




class BoardView
{
	int x0 = 10, y0 = 10, columns = 4, rows = 2, size = 40, gap = 1;
	std::vector<sf::RectangleShape> rectangles;
	sf::RenderWindow &renderWindow;
	Board &board;	
	void setRectanglesVector();
	void setWindowSize();
	

public:
	BoardView(Board &board, sf::RenderWindow &renderWindow);
	void draw();
};

