#include "pch.h"
#include "ScoreView.h"
#include <string>

ScoreView::ScoreView(Board &board) : board(board)
{
	if (!font.loadFromFile("arial.ttf")) {
		abort();
	}
}

void ScoreView::draw(sf::RenderWindow &renderWindow)
{
	if (!(renderWindow.getSize().x == 600 && renderWindow.getSize().y == 500)) setWindowSize(renderWindow);
	txt.setString("SNAKE'S LENGTH: " + std::to_string(board.getSnakeLength()));
	txt.setFont(font);
	txt.setFillColor(sf::Color::Red);
	txt.setPosition(135, 100);
	txt.setCharacterSize(20);
	renderWindow.draw(txt);


	rect_exit.setSize(sf::Vector2f(100, 50));
	rect_exit.setPosition(250, 190);
	rect_exit.setFillColor(sf::Color::Green);
	txt.setFont(font);
	txt.setString("EXIT");
	txt.setPosition(275, 200);
	txt.setFillColor(sf::Color::Red);
	txt.setCharacterSize(20);

	renderWindow.draw(rect_exit);
	renderWindow.draw(txt);

	rect_play_again.setSize(sf::Vector2f(150, 50));
	rect_play_again.setPosition(225, 300);//setPosition(195, 100);
	rect_play_again.setFillColor(sf::Color::Green);
	txt.setFont(font);
	txt.setString("PLAY AGAIN");
	txt.setPosition(235, 310);
	txt.setFillColor(sf::Color::Red);
	txt.setCharacterSize(20);

	renderWindow.draw(rect_play_again);
	renderWindow.draw(txt);
}

void ScoreView::setWindowSize(sf::RenderWindow &renderWindow)
{
	sf::View view;
	view.setSize(renderWindow.getSize().x, renderWindow.getSize().y);
	renderWindow.setView(view);
	renderWindow.create(sf::VideoMode(600, 500), "SNAKE");
}


