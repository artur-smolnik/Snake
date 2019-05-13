#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Board.h"
class IntroView
{
	sf::RectangleShape rect;	
	sf::Font font;
	sf::Text txt;
	sf::Text txt_play;	
	sf::RenderWindow &renderWindow;	
	sf::Text identities;

public:
	IntroView(sf::RenderWindow &renderWindow);	
	sf::RenderWindow &getWindow() { return renderWindow; }	
	sf::RectangleShape &getRect() { return rect; }
	void draw();

	
};

