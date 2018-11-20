#include "After.h"
#include "InputHandler.h"
#include "TextureManager.h"

void After::handleInput()
{
}

After::After(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

void After::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}

void After::collision(GameObject * pCollider)
{
	if (pCollider->GetTag() == "bullet")
	{
		m_textureID = "after";
	}
}

void After::update()
{
	m_velocity.setX(0);
	handleInput(); // add our function
	m_currentFrame = int(((SDL_GetTicks() / 100) % 1));
	SDLGameObject::update();
}
void After::clean()
{
}