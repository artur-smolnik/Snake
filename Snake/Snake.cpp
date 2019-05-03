#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Board.h"
#include "BoardView.h"
#include "BoardController.h"
#include <Windows.h>

int main()
{
	srand(time(NULL));
	int x0 = 10, y0 = 10, columns = 4, rows = 2, size = 80, gap = 5;

	sf::RenderWindow renderWindow(sf::VideoMode(600, 500), "SAPER");

	Board board(10,10,NORMAL);
	BoardView boardView(board, renderWindow);
	BoardController boardController(boardView, board);

	boardController.draw();
	renderWindow.display();
	Sleep(10000);


	//while (window.isOpen())
	//{

	//	sf::Event event;

	//	while (window.pollEvent(event))
	//	{
	//		if (event.type == sf::Event::Closed)window.close();
	//	}

	//	/*window.clear();
	//	gameManager.handleEvent();
	//	gameManager.draw();
	//	window.display();*/
	//}

	std::cout << std::endl << "Koniec gry";
	return EXIT_SUCCESS;
}