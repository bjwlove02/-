#include "Game.h"

void Monster::update()
{
	if (m_x < 400) {
		m_x += 1;
	}
	else if (m_x > 100) {
		m_x -= 1;
	}
}
