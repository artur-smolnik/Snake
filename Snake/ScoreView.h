#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"
class ScoreView
{
	sf::RectangleShape rect_exit;
	sf::RectangleShape rect_play_again;
	sf::Font font;	
	sf::Text txt;
	bool isWindowSet; //prevent from window flickering
	Board &board;
	void setWindowSize(sf::RenderWindow &renderWindow);
public:
	ScoreView(Board &board);
	void draw(sf::RenderWindow &renderWindow);
};

