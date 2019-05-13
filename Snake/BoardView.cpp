#include "pch.h"
#include "BoardView.h"
#include <Windows.h>


BoardView::BoardView(Board &board):board(board)
{
	setRectanglesVector();

}

void BoardView::setRectanglesVector()
{
	for (int i = 0; i < board.getRows(); i++)
	{
		for (int j = 0; j < board.getColumns(); j++)
		{
			sf::RectangleShape rectangle(sf::Vector2f(size, size));
			rectangle.setFillColor(sf::Color::Green);
			rectangle.setPosition(y0 + j * size + j * gap, x0 + i * size + i * gap); 
			rectangles.push_back(rectangle);			

		}
	}
}

void BoardView::draw(sf::RenderWindow &renderWindow)
{		
	
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
		Sleep(150);
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
	}
}
