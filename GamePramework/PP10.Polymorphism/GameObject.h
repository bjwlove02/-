#pragma once
#include "TextureManager.h"

class GameObject
{
public:
	virtual void load(int x, int y, int width, int height,
		std::string textureID);
	virtual void draw(SDL_Renderer* pRenderer);
	virtual void update();
	virtual void clean() {}
	void SetMoveSpeed(int speed)
	{
		m_Speed = speed;
	}
protected:
	std::string m_textureID;
	int m_currentFrame;
	int m_currentRow;
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	int m_Speed = 1;
	int m_Count = 0;
};