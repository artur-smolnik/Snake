#pragma once
#include"SFML/Graphics.hpp"
#include "BoardController.h"
#include "ScoreController.h"


class GameManager {
	BoardController &boardController;
	ScoreController &scoreController;
	enum GameState {
		INTRO, GAME, SCORE
	} state;

	void updateState();
public:
	GameManager(BoardController &boardController, ScoreController &scoreController);

	void draw(sf::RenderWindow &renderWindow);

	void handleEvent(sf::Event &event);
};




