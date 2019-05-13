#include "pch.h"
#include "BoardView.h"
#include <Windows.h>
#include <string>
#include <iostream>




BoardView::BoardView(Board &board) : board(board)
{
	setRectanglesVector();
	if (!font.loadFromFile("arial.ttf")) abort();

	if (!topLeft.loadFromFile("topLeft.jpg"))std::cout << "ERROR topLeft";
	if (!topRight.loadFromFile("topRight.jpg"))std::cout << "ERROR topRight";
	if (!downLeft.loadFromFile("downLeft.jpg"))std::cout << "ERROR downLeft";
	if (!downRight.loadFromFile("downRight.jpg"))std::cout << "ERROR downRight";
	if (!emptyField.loadFromFile("emptyField.jpg"))std::cout << "ERROR emptyField";
	if (!tail.loadFromFile("tail.jpg"))std::cout << "ERROR tail";
	if (!head.loadFromFile("head.jpg"))std::cout << "ERROR head";
	if (!body.loadFromFile("body.jpg"))std::cout << "ERROR body";
	if (!food.loadFromFile("food.jpg"))std::cout << "ERROR food";

	txt.setString("SNAKE'S LENGTH: " + std::to_string(board.getSnakeLength()));
	txt.setFont(font);
	txt.setFillColor(sf::Color::Red);
	txt.setPosition((x0 + board.getColumns() * size + board.getColumns() * gap)/2-130, 0);
	txt.setCharacterSize(30);
	
}

void BoardView::setCurrentScore()
{
	txt.setString("SNAKE'S LENGTH: " + std::to_string(board.getSnakeLength()));
}

void BoardView::setRectanglesVector()
{
	for (int i = 0; i < board.getRows(); i++)
	{
		for (int j = 0; j < board.getColumns(); j++)
		{
			sf::RectangleShape rectangle(sf::Vector2f(size, size));
			rectangle.setFillColor(sf::Color::Green);
			rectangle.setPosition(x0 + j * size + j * gap, 60 + y0 + i * size + i * gap);
			rectangles.push_back(rectangle);			
		}
	}
}

void BoardView::setWindowSize(sf::RenderWindow &renderWindow)
{
	int x, y;
	x = board.getColumns() * size + 2 * x0 + (board.getColumns() - 1)*gap;
	y = 60 + board.getRows() * size + 2 * y0 + (board.getRows() - 1)*gap;
	sf::View view;
	view.setSize(renderWindow.getSize().x, renderWindow.getSize().y);
	renderWindow.setView(view);
	renderWindow.create(sf::VideoMode(x, y), "SNAKE");	
}

void BoardView::draw(sf::RenderWindow &renderWindow)
{		
	
	if (!(renderWindow.getSize().x == board.getColumns() * size + 2 * x0 + (board.getColumns() - 1)*gap && renderWindow.getSize().y == 60 + board.getRows() * size + 2 * y0 + (board.getRows() - 1)*gap)) setWindowSize(renderWindow);
	
	if (board.isFinished())
	{
		for (int i = 0; i < board.getRows(); i++)
		{
			for (int j = 0; j < board.getColumns(); j++)
			{
				if (board.hasSnake(i, j)) rectangles[i*board.getColumns() + j].setFillColor(sf::Color::Black);				
			}
		}
		for (int i = 0; i < rectangles.size(); i++)
		{
			renderWindow.draw(rectangles[i]);
		}
		renderWindow.display();
		Sleep(3000);
	}
	else
	{
		Sleep(120);
		/*for (int i = 0; i < board.getSnakePosition().size(); i++)
		{
			if (i == 0)
			{
				rectangles[board.getSnakePosition().front().row*board.getColumns() + board.getSnakePosition().front().col].setTexture(&head);
			}
			else if(i > 0 && i < board.getSnakePosition().size() - 1)
			{
				rectangles[board.getSnakePosition().front().row*board.getColumns() + board.getSnakePosition().front().col].setTexture(&body);
			}
			else if (i == board.getSnakePosition().size() - 1)
			{
				rectangles[board.getSnakePosition().front().row*board.getColumns() + board.getSnakePosition().front().col].setTexture(&tail);
			}
		}
		for (int i = 0; i < board.getRows(); i++)
		{
			for (int j = 0; j < board.getColumns(); j++)
			{				
				if (board.hasFood(i, j)) rectangles[i*board.getColumns() + j].setTexture(&food);
				if (!board.hasFood(i, j) && !board.hasSnake(i, j)) rectangles[i*board.getColumns() + j].setTexture(&emptyField);
			}
		}

*/

		
		for (int i = 0; i < board.getRows(); i++)
		{
			for (int j = 0; j < board.getColumns(); j++)
			{
				if (board.hasSnake(i, j) == true) rectangles[i*board.getColumns() + j].setFillColor(sf::Color::Red);
				else if (board.hasFood(i, j) && !board.hasSnake(i, j)) rectangles[i*board.getColumns() + j].setFillColor(sf::Color::Blue);
				else rectangles[i*board.getColumns() + j].setFillColor(sf::Color::Green);
			}
		}

		for (int i = 0; i < rectangles.size(); i++)
		{
			renderWindow.draw(rectangles[i]);
		}
		setCurrentScore();
		renderWindow.draw(txt);
	}
}
