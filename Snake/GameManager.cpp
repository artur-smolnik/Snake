#include "pch.h"
#include "GameManager.h"


GameManager::GameManager(BoardController &boardController, ScoreController &scoreController, IntroController &introController) 
	: boardController(boardController), scoreController(scoreController), introController(introController)
{
	state = INTRO;
}
void GameManager::updateState() {
	switch (state) {
	case INTRO:
		if (introController.isFinished())
			state = GAME;
		break;
	case GAME:
		if (boardController.isFinished())
			state = SCORE;
		break;
	case SCORE:
		// oops - tu powinniœmy jakoœ zamkn¹æ aplikacjê
		break;
	}
}

void GameManager::handleEvent(sf::Event &event)
{
	switch (state) {
	case INTRO:
		introController.handleEvent();
		break;
	case GAME:
		boardController.handleEvent(event);
		break;
	case SCORE:
		scoreController.handleEvent();
		break;
	}
	//updateState();
}

void GameManager::draw(sf::RenderWindow &renderWindow) {
	//updateState() ??
	switch (state) {
	case INTRO:
		introController.draw();
		break;
	case GAME:
		boardController.draw(renderWindow);
		break;
	case SCORE:
		scoreController.draw(renderWindow);
		break;
	}
	updateState();
}