#include "Bullet.h"
#include "InputHandler.h"
#include "Game.h"
#include <iterator>

Bullet::Bullet(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

void Bullet::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}

void Bullet::update()
{
	m_velocity.setX(5);
	m_currentFrame = int(((SDL_GetTicks() / 100) % 1));
	SDLGameObject::update();
}

void Bullet::clean()
{
}