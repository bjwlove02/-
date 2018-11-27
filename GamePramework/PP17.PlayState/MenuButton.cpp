#include "MenuButton.h"

void MenuButton::draw()
{
	SDLGameObject::draw(); // use the base class drawing
}


void MenuButton::clean()
{
	SDLGameObject::clean();
}

MenuButton::MenuButton(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

void MenuButton::update()
{
	SDLGameObject::update();
}
