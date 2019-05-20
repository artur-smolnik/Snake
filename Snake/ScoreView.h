#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"
class ScoreView
{
	sf::RectangleShape rect_exit;
	sf::RectangleShape rect_play_again;
	sf::Font font;	
	sf::Text txt;
	Board &board;
	void setWindowSize(sf::RenderWindow &renderWindow);
	sf::RenderWindow &renderWIndow;
public:
	ScoreView(Board &board, sf::RenderWindow &renderWIndow);
	void draw(sf::RenderWindow &renderWindow);
	sf::RectangleShape getRectExit() { return rect_exit; }
	sf::RectangleShape getRectPlayAgain() { return rect_play_again; }
	sf::RenderWindow &getWindow() { return renderWIndow; }
};

