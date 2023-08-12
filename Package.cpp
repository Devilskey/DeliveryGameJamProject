#include "Package.h"

Package::Package()
{
	type = "package";
	y = 560;
}

void Package::RenderObject()
{
	object = { (float)x, (float)y, 50, 50 };
	DrawRectangle(x, y, 50, 50, RAYWHITE);
}

void Package::ObjectFunction()
{
	x -= 3;
}

void Package::CheckCollisions(GameObject* gameObject1, GameObject* gameObject2, const char* Type)
{
	if (CheckCollisionRecs(gameObject1->object, gameObject2->object)) {
		if (Type == "player") {
			collected = true;
			score += 50;
			Packages += 1;
		}
	}
}

bool Package::GameObjectKillSwitch()
{
	if (x <= -10) {
		return true;
	}
	return collected;
}
