#pragma once
#include "SDLGameObject.h"

class Enemy : public SDLGameObject
{
private:
	int m_numFrames;
	void handleInput();

public:
	Enemy(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
};