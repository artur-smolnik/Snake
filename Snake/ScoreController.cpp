#include "pch.h"
#include "ScoreController.h"


ScoreController::ScoreController(ScoreView &scoreView) : scoreView(scoreView)
{
}

void ScoreController::draw(sf::RenderWindow &renderWindow)
{
	scoreView.draw(renderWindow);
}

