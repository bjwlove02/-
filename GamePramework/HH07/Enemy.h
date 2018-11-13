#pragma once
#include "SDLGameObject.h"

class Enemy : public SDLGameObject
{
public:
	Enemy(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void collision(GameObject* pCollider);
private:
	void handleInput();
};
