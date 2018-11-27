#include "Game.h"
#include "InputHandler.h"
#include "Vector2D.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

void Enemy::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}

void Enemy::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Enemy::clean()
{
}