#include "PlayState.h"
#include "InputHandler.h"
#include "GameStateMachine.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "Game.h"

PlayState* PlayState::s_pInstance = 0;
const std::string PlayState::s_playID = "PLAY";

void PlayState::update()
{
	GameState::update();
	if (checkCollision(
		dynamic_cast<SDLGameObject*>(m_gameObjects[0]),
		dynamic_cast<SDLGameObject*>(m_gameObjects[1])))
	{
		TheGame::Instance()->getStateMachine()->changeState(
			GameOverState::Instance());
	}

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->changeState(
			PauseState::Instance());
	}

}

void PlayState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool PlayState::onEnter()
{

	if (!TheTextureManager::Instance()->load("assets/helicopter.png",
		"helicopter", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/helicopter2.png",
		"helicopter2", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/bullet.png",
		"bullet", TheGame::Instance()->getRenderer())) {
		return false;
	}
	
	int random = rand() % 1000;

	GameObject* player = new Player(
		new LoaderParams(1400, 100, 128, 55, "helicopter"));
		GameObject* enemy = new Enemy(
			new LoaderParams(random, random, 128, 55, "helicopter2"));
		m_gameObjects.push_back(enemy);
	GameObject* bullet = new Bullet(
		new LoaderParams(100, 100, 500, 500, "bullet"));
	
	m_gameObjects.push_back(player);
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE)) {
		m_gameObjects.push_back(bullet);
	}

	std::cout << "entering PlayState\n";
	return true;
}

bool PlayState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	TheTextureManager::Instance()->clearFromTextureMap("helicopter");
	std::cout << "exiting PlayState\n";
	return true;
}

bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject* p2)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = p1->getPosition().getX();
	rightA = p1->getPosition().getX() + p1->getWidth();
	topA = p1->getPosition().getY();
	bottomA = p1->getPosition().getY() + p1->getHeight();

	//Calculate the sides of rect B
	leftB = p2->getPosition().getX();
	rightB = p2->getPosition().getX() + p2->getWidth();
	topB = p2->getPosition().getY();
	bottomB = p2->getPosition().getY() + p2->getHeight();

	//If any of the sides from A are outside of B
	if (bottomA <= topB) { return false; }
	if (topA >= bottomB) { return false; }
	if (rightA <= leftB) { return false; }
	if (leftA >= rightB) { return false; }
	return true;
}