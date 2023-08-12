#include "coin.h"

void coin::RenderObject()
{
	object = { (float)x, (float)y, (float)20, (float)20 };
	//DrawRectangle(x, y, 20, 20, YELLOW);
	DrawCircle(x, y, 20, YELLOW);
}

void coin::ObjectFunction()
{
	x -= 3;
}

void coin::CheckCollisions(GameObject* gameObject1, GameObject* gameObject2, const char* Type)
{
	if (CheckCollisionRecs(gameObject1->object, gameObject2->object)) 
	{
		if (Type == "player") 
		{
			score += 25;
			Collected = true;
		}
	}
}

bool coin::GameObjectKillSwitch()
{
	if (x <= -10) {
		return true;
	}
	return Collected;
}
