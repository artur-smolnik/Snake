#include "pch.h"
#include "IntroController.h"


IntroController::IntroController(IntroView &introView, Board &board) : introView(introView), board(board)
{
}

void IntroController::handleEvent()
{
	auto mouse_pos = sf::Mouse::getPosition(introView.getWindow());  // those two lines can be found on sfml forum 
	auto translated_pos = introView.getWindow().mapPixelToCoords(mouse_pos);
	
	if (introView.getRect().getGlobalBounds().contains(translated_pos))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			finished = true;			
		}
	}
}

void IntroController::draw()
{
	introView.draw();
}


