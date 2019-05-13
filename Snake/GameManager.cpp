#include "pch.h"
#include "GameManager.h"


GameManager::GameManager(BoardController &boardController) : boardController(boardController)
{
	state = GAME;
}
void GameManager::updateState() {
	switch (state) {
	case INTRO:
		//if (introController.isFinished())
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
		//introController.handleEvent(event);
		break;
	case GAME:
		boardController.handleEvent(event);
		break;
	case SCORE:
		//scoreController.handleEvent(event);
		break;
	}
	//updateState();
}

void GameManager::draw(sf::RenderWindow &renderWindow) {
	//updateState() ??
	switch (state) {
		//case INTRO:
			//introController.draw(win);
		break;
	case GAME:
		boardController.draw(renderWindow);
		break;
	case SCORE:
		//scoreController.draw(win);
		break;
	}
	updateState();
}