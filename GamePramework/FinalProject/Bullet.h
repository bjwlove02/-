#pragma once
#include "SDLGameObject.h"
#include <iostream>
using namespace std;

class Bullet : public SDLGameObject
{
public:
	Bullet(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
}; 
