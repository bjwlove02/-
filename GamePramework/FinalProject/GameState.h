#pragma once
#include<string>
#include <vector>

class GameObject;

class GameState
{
public:
	std::vector<GameObject*> m_gameObjects;
	virtual void update();
	virtual void render();
	virtual bool onEnter() = 0;
	virtual bool onExit() = 0;
	virtual std::string getStateID() const = 0;
};