#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "GameStateMachine.h"

class Game
{
public:
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	void quit();
	bool running() { return m_bRunning; }

	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}

	GameStateMachine* getStateMachine() { return m_pGameStateMachine; }
	SDL_Renderer* getRenderer() const { return m_pRenderer; }
	std::vector<GameObject*>* GetGameObjects() {
		return &m_gameObjects;
	}
private:
	Game() {}
	static Game* s_pInstance;

	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	std::vector<GameObject*> m_gameObjects;

	bool m_bRunning;

	int m_currentFrame;

	GameStateMachine* m_pGameStateMachine;	
};
typedef Game TheGame;
