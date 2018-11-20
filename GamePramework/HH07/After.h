#pragma once
#include "SDLGameObject.h"
#include <iostream>
using namespace std;

class After : public SDLGameObject
{
private:
	void handleInput();
public:
	After(const LoaderParams* pParams);
	virtual void draw();
	virtual void collision(GameObject* pCollider);
	virtual void update();
	virtual void clean();
};