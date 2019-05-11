#pragma once
#include"SFML/Graphics.hpp"
#include "BoardController.h"


class GameManager {
	BoardController &boardController;
	enum GameState {
		INTRO, GAME, SCORE
	} state;

	void updateState();
public:
	GameManager(BoardController &boardController);

	void draw(sf::RenderWindow &renderWindow);

	void handleEvent(sf::Event &event);
};




