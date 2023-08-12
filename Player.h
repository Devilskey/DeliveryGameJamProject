#include "GameObject.h"
#include "raylib.h"
#include "Game.h"
#include <iostream>

using namespace std;

#pragma once
class Player : public GameObject
{
	public:
		Player() {
			type = "player";
		}
		bool GameObjectKillSwitch();
		void Input();
		void Gravity();
		void Checkhealth();

	public:
		void CheckCollisions(GameObject* gameObject1, GameObject* gameObject2, const char* Type) {
			if (CheckCollisionRecs(gameObject1->object, gameObject2->object)) {
				if (Type == "ObsticalBox") {
					health -= 1;
				}
			}
		}

		void RenderObject() {
			DrawText(TextFormat("health: %d", health), 0, 40, 30, RAYWHITE);
			object = {(float)x, (float)y, (float)WIDTH, (float)HEIGHT};
			Vector2 pos = { x, y };
			DrawTexture(playerSprite,x,y,WHITE);

		};

		void ObjectFunction() {
			if (Packages == 10) {
				health += 1;
				Packages = 0;
			}
			Input();
			Checkhealth();
			Gravity();
		};
		Texture2D playerSprite;

		void LoadTextures();

	private:
		int health = 3;
		int x = 120;
		int y = 500;
		int speed = 3;
		const int WIDTH = 100;
		const int HEIGHT = 100;
		const int gravityForcePower = 1;
		double gravityForce = 0;
		bool grounded = false;
		bool invins = false;
};
