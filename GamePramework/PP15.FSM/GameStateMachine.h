#pragma once
#include "GameState.h"

class GameStateMachine
{
public:
	void render();
	void update();
	void popState();
	void changeState(GameState* pState);
	void pushState(GameState *pState);

private:
	GameState * m_currentState;
	GameState* m_prevState;

	std::vector<GameState*> m_gameStates;
};