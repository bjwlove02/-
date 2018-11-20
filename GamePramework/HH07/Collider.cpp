#include "Collider.h"
#include "SDLGameObject.h"

Collider* Collider::s_pInstance = 0;

bool Collider::Collsion(GameObject * collider1, GameObject * collider2)
{
	float left1, top1, right1, botton1;
	float left2, top2, right2, botton2;

	left1 = ((SDLGameObject*)collider1)->GetPos().getX();
	left2 = ((SDLGameObject*)collider2)->GetPos().getX();

	top1 = ((SDLGameObject*)collider1)->GetPos().getY();
	top2 = ((SDLGameObject*)collider2)->GetPos().getY();

	right1 = ((SDLGameObject*)collider1)->GetPos().getX() + ((SDLGameObject*)collider1)->GetWidth();
	right2 = ((SDLGameObject*)collider2)->GetPos().getX() + ((SDLGameObject*)collider2)->GetWidth();

	botton1 = ((SDLGameObject*)collider1)->GetPos().getY() + ((SDLGameObject*)collider1)->GetHeight();
	botton2 = ((SDLGameObject*)collider2)->GetPos().getY() + ((SDLGameObject*)collider2)->GetHeight();

	if (left1 < right2 &&
		top1 < botton2 &&
		right1 > left2 &&
		botton1 > top2)
		return true;
	else
		return false;
}