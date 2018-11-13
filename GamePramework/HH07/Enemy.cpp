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
}

void Enemy::clean()
{
}

void Enemy::collision(GameObject* pCollider) 
{
}