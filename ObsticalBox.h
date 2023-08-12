#include "GameObject.h";
#include "raylib.h"
#include "Game.h"

#pragma once
class ObsticalBox : public GameObject
{
public:
	ObsticalBox(int width, int height) {
		type = "ObsticalBox";
		y -= height;
		x += ((height / 10) * (width / 10)) * (height / 3.14);
		speed += (height / 40);
		this->width = width;
		if (height > 20)
			this->height = height;
		else
			this->height = 50;
		if(width > 20)
			this->width = width;
		else 
			this->width = 50;
	}

	void ForceBack();
	void RenderObject();

	bool GameObjectKillSwitch();

	void CheckCollisions(GameObject* gameObject1, GameObject* gameObject2, const char* Type) {
		if (CheckCollisionRecs(gameObject1->object, gameObject2->object)) {
			if (Type == "player") {
				x = -300;
			}
		}
	}

	void ObjectFunction() {
		ForceBack();
	}

private:
	int y = (720 - 40);
	int x = 1300;
	int speed = 3;
	int width = 50;
	int height = 50;
};
