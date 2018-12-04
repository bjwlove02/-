#pragma once

#include "GameState.h"

class GameObject;

class PauseState : public GameState {
public:
	static PauseState* Instance() {
		if (s_pInst == 0)
			s_pInst = new PauseState;
		return s_pInst;
	}

	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_pauseID; }

private:
	static PauseState* s_pInst;
	PauseState() {};

	static void s_pauseToMain();
	static void s_resumePlay();
	static const std::string s_pauseID;
};