#pragma once
#include "GameState.h"

class GameObject;

class GameOverState : public GameState
{
private:
	static GameOverState* s_pInst;
	static void s_gameOverToMain();
	static void s_restartPlay();
	static const std::string s_gameOverID;

public:
	GameOverState() {}
	static GameOverState* Instance() {
		if (s_pInst == 0)
			s_pInst = new GameOverState;
		return s_pInst;
	}

	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_gameOverID; }
};