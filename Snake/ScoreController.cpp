#include "pch.h"
#include "ScoreController.h"


ScoreController::ScoreController(ScoreView &scoreView) : scoreView(scoreView)
{
}

void ScoreController::handleEvent()
{
	auto mouse_pos = sf::Mouse::getPosition(scoreView.getWindow());         // those two lines can be found on sfml forum 
	auto translated_pos = scoreView.getWindow().mapPixelToCoords(mouse_pos);
	//------------------ alternative version
	/*if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{		
		if (scoreView.getRectExit().getGlobalBounds().contains(scoreView.getWindow().mapPixelToCoords(sf::Mouse::getPosition(scoreView.getWindow()))))
		{
			finished = true;
		}
	}*/
	//------------------
	if (scoreView.getRectExit().getGlobalBounds().contains(translated_pos)) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			finished = true;
		}
	}
	if (scoreView.getRectPlayAgain().getGlobalBounds().contains(translated_pos)) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			again = true;
		}
	}
}

void ScoreController::draw(sf::RenderWindow &renderWindow)
{
	scoreView.draw(renderWindow);
}

