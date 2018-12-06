#include "Player.h"
#include "InputHandler.h"
#include "GameStateMachine.h"
#include "Game.h"

void Player::handleInput()
{
	Vector2D* target = TheInputHandler::Instance()->getMousePosition();
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE)) {
		GameObject* bullet = new Bullet(
			new LoaderParams(m_position.getX() + 100, m_position.getY() + 10, 32, 32, "bullet"));
		m_gameObjects.push_back(bullet);
	}
	m_velocity = *target - m_position;
	m_velocity /= 50;
}

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

void Player::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}

void Player::update()
{
	m_velocity.setX(0);
	m_velocity.setY(0);
	handleInput(); // add our function
	m_currentFrame = int(((SDL_GetTicks() / 100) % 5));
	SDLGameObject::update();
}
void Player::clean()
{
}