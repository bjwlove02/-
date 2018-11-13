#include "Player.h"
#include "InputHandler.h"
#include "Bullet.h"
#include "Game.h"

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
	handleInput();
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	SDLGameObject::update();
}

void Player::clean()
{
}

void Player::handleInput() {
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
		m_velocity.setX(2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
		m_velocity.setX(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
		m_velocity.setY(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
		m_velocity.setY(2);
	}
	if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
	{
		m_velocity.setX(1);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
	{
		Game::Instance()->GetGameObjects()->push_back(new Bullet(new LoaderParams(m_position.getX()+100, m_position.getY()+10, 32, 32, "bullet","bullet")));
	}
	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	m_velocity = (*vec - m_position) / 100;
}

void Player::collision(GameObject* pCollider)
{
}