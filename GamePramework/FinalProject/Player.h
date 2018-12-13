#pragma once
#include "SDLGameObject.h"
#include "Bullet.h"

class GameState;
class Player : public SDLGameObject
{
private:
	void handleInput();

public:
	Player(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
};