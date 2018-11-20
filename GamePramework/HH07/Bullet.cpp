#include "Bullet.h"
#include "InputHandler.h"
#include "Game.h"
#include <iterator>

void Bullet::handleInput()
{
}

Bullet::Bullet(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

void Bullet::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}

void Bullet::collision(GameObject * pCollider)
{
	if (pCollider->GetTag() == "before")
	{
		vector<GameObject*>::iterator iter = Game::Instance()->GetGameObjects()->begin();
		vector<GameObject*>::iterator iterEnd = Game::Instance()->GetGameObjects()->end();
		for (; iter != iterEnd; iter++)
		{
			if (*iter == this) {
				Game::Instance()->GetGameObjects()->erase(iter);
				break;
			}
		}
	}
}

void Bullet::update()
{
	m_velocity.setX(5);
	handleInput(); // add our function
	m_currentFrame = int(((SDL_GetTicks() / 100) % 1));
	SDLGameObject::update();
}
void Bullet::clean()
{
}