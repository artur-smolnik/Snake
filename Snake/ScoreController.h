#pragma once
#include <SFML/Graphics.hpp>
#include "ScoreView.h"
class ScoreController
{
	ScoreView &scoreView;
	bool finished;
	bool again;

public:
	ScoreController(ScoreView &scoreView);
	void handleEvent();
	void draw(sf::RenderWindow &renderWindow);
	bool isFinished() const { return finished; }
	bool playAgain() { return again; }
	void setPlayAgainToFalse() { again = false; }
	void setFinishedToFalse() { finished = false; }
	
};

