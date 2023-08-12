#include "raylib.h"
#pragma once
class GameObject
{
public:
	virtual void RenderObject() = 0;
	virtual void ObjectFunction() = 0;
	Rectangle object;
	const char* type;
	virtual void CheckCollisions(GameObject* gameObject1, GameObject* gameObject2, const char* Type) = 0;
	virtual bool GameObjectKillSwitch() = 0;
};