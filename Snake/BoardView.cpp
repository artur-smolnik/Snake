#include "pch.h"
#include "BoardView.h"


BoardView::BoardView(Board &board, sf::RenderWindow &renderWindow):board(board), renderWindow(renderWindow)
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
			rectangle.setPosition(y0 + i * size + i * gap, x0 + j * size + j * gap); //cols,rows
			rectangles.push_back(rectangle);
		}
	}
}

void BoardView::draw()
{
	
	for (int i = 0; i < rectangles.size(); i++)
	{
		renderWindow.draw(rectangles[i]);
	}
}
