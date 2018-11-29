#pragma once
#include "TextureManager.h"
#include "GameState.h"

class GameObject;

class PauseState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();

	static PauseState* Instance()
	{
		if (ss_pInstance == 0)
		{
			ss_pInstance = new PauseState();
			return ss_pInstance;
		}
		return ss_pInstance;
	}

	virtual std::string getStateID() const { return s_pauseID; }
private:
	static void s_pauseToMain();
	static void s_resumePlay();
	static PauseState* ss_pInstance;
	static const std::string s_pauseID;
	std::vector<GameObject*> m_gameObjects;
};