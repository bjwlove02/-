#include "Game.h"
#include <SDL_image.h>
#include "Collider.h"
#include "InputHandler.h"
#include "After.h"

Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {

	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
		if (m_pWindow != 0) {
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}

		m_bRunning = true;
		if (!TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", m_pRenderer))
		{
			return false;
		}
		if (!TheTextureManager::Instance()->load("assets/before.png", "before", m_pRenderer))
		{
			return false;
		}
		if (!TheTextureManager::Instance()->load("assets/bullet.png", "bullet", m_pRenderer))
		{
			return false;
		}
		if (!TheTextureManager::Instance()->load("assets/after.png", "after", m_pRenderer))
		{
			return false;
		}

		m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate","animate")));
		m_gameObjects.push_back(new After(new LoaderParams(400, 200, 50, 50, "before","before")));
		SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);

	}
	else {
		return false;
	}
	return true;
}

void Game::render() {
	SDL_RenderClear(m_pRenderer);
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
	SDL_RenderPresent(m_pRenderer);
}

void Game::update() {
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}

	for (int i = 0; i < m_gameObjects.size() - 1; i++)
	{
		for (int j = i + 1; j < m_gameObjects.size(); j++)
		{
			if (Collider::Instance()->Collsion(m_gameObjects[i], m_gameObjects[j]))
			{
				m_gameObjects[i]->collision(m_gameObjects[j]);
				m_gameObjects[j]->collision(m_gameObjects[i]);	
			}
		}
	}
}

void Game::clean() {
	std::cout << "cleaning game\n"; 
	TheInputHandler::Instance()->clean();
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_RenderPresent(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents() {
	TheInputHandler::Instance()->update();
}
