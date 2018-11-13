#pragma once
#include "LoaderParams.h"

class GameObject
{
public:
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;
	virtual void collision(GameObject* pCollider) = 0;

	string GetTag() { return m_tag; }

protected:
	string m_tag;
	
	GameObject(const LoaderParams* pParams) {}
	virtual ~GameObject() {}
};