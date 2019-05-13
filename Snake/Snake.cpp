#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Board.h"
#include "BoardView.h"
#include "BoardController.h"
#include <Windows.h>
#include "GameManager.h"

int main()
{
	srand(time(NULL));
	int x0 = 10, y0 = 10, columns = 4, rows = 2, size = 80, gap = 5;

	sf::RenderWindow renderWindow(sf::VideoMode(600, 500), "SNAKE");

	Board board(10,10,NORMAL);
	BoardView boardView(board);
	BoardController boardController(boardView, board);
	GameManager gameManager(boardController);
	
	//boardView.draw(renderWindow);
	//renderWindow.display();
	//Sleep(3000);
	while (true)
	{
		sf::Event event;
		renderWindow.pollEvent(event);
		renderWindow.clear();
		gameManager.handleEvent(event);
		gameManager.draw(renderWindow);
		//boardView.draw(renderWindow);
		renderWindow.display();
	}
	while (renderWindow.isOpen())
	{

		sf::Event event;

		while (renderWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)renderWindow.close();
		}

		renderWindow.clear();
		gameManager.handleEvent(event);
		gameManager.draw(renderWindow);
		renderWindow.display();
	}

	std::cout << std::endl << "Koniec gry";
	return EXIT_SUCCESS;
}