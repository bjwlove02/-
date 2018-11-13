#pragma once
class GameObject;

class Collider
{
private:
	Collider() {}
	static Collider* s_pInstance;
public:
	static Collider* Instance() {
		if (s_pInstance == 0)
		{
			s_pInstance = new Collider();
		}
		return s_pInstance;
	}

private:

public:
	bool Collsion(GameObject* collder1, GameObject* collider2);
};