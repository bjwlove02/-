#include "Game.h"

void Monster::update()
{
	m_x += m_Speed;
	m_Count++;
	if (m_Count > 200)
	{
		m_Speed *= -1;
		m_Count = 0;
	}
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}
