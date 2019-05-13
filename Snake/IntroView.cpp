#include "pch.h"
#include "IntroView.h"


IntroView::IntroView(sf::RenderWindow &renderWindow) : renderWindow(renderWindow)
{
}

void IntroView::draw()
{
	if (!font.loadFromFile("arial.ttf")) {
		abort();
	}

	txt.setFont(font);
	txt.setString("SNAKE");
	txt.setPosition(300, 20);
	txt.setOutlineThickness(4);
	txt.setOutlineColor(sf::Color::Blue);
	txt.setFillColor(sf::Color::Green);
	txt.setCharacterSize(50);
	renderWindow.draw(txt);

	rect.setSize(sf::Vector2f(100, 100));
	rect.setPosition(100, 100);
	txt_play.setFont(font);
	txt_play.setFillColor(sf::Color::Red);
	txt_play.setString("Play");
	txt_play.setPosition(120, 125);
	txt.setCharacterSize(20);
	renderWindow.draw(rect);
	renderWindow.draw(txt_play);


	identities.setFont(font);
	identities.setString("Artur Smolnik 249092");
	identities.setPosition(100, 450);
	identities.setFillColor(sf::Color::Red);
	identities.setCharacterSize(15);
	renderWindow.draw(identities);


}
