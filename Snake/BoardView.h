#pragma once
#include "SFML/Graphics.hpp"
#include "Board.h"




class BoardView
{
	int x0 = 10, y0 = 10, size = 40, gap = 1;
	std::vector<sf::RectangleShape> rectangles;
	
	Board &board;	
	void setRectanglesVector();
	void setWindowSize(sf::RenderWindow &renderWindow);
	

	

public:
	BoardView(Board &board);
	void draw(sf::RenderWindow &renderWindow);
};

