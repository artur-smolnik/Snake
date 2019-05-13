#pragma once
#include"SFML/Graphics.hpp"
#include "BoardController.h"
#include "ScoreController.h"
#include "IntroController.h"


class GameManager {
	BoardController &boardController;
	ScoreController &scoreController;
	IntroController &introController;
	enum GameState {
		INTRO, GAME, SCORE
	} state;

	void updateState();
public:
	GameManager(BoardController &boardController, ScoreController &scoreController, IntroController &introController);

	void draw(sf::RenderWindow &renderWindow);

	void handleEvent(sf::Event &event);
};




