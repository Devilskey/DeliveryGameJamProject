#include "GameObject.h"

#pragma once
#include "Game.h"
class Package : public GameObject
{
public:
	Package();
	void RenderObject();
	void ObjectFunction();
	void CheckCollisions(GameObject* gameObject1, GameObject* gameObject2, const char* Type);
	bool GameObjectKillSwitch();

private:
	int x = 1500;
	int y;
	bool collected = false;
};
