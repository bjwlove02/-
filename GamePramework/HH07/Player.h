#pragma once
#include "SDLGameObject.h"

class Player : public SDLGameObject
{
public:
	Player(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void collision(GameObject* pCollider);
private:
	void handleInput();
};