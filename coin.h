#include "GameObject.h"
#include "Game.h"
#pragma once
#include <iostream>
#include <random>

using namespace std;

class coin : public GameObject
{
	public:
		coin() {
			random_device random;
			mt19937 gen(random());
			uniform_int_distribution<> newYpos(500, 650);
			uniform_int_distribution<> ExtraX(0, 400);

			type = "coin";
			x = 1300;
			y = newYpos(gen);
			x += ExtraX(gen);
			Collected = false;
		}
	
		void RenderObject();
		void ObjectFunction();
		void CheckCollisions(GameObject* gameObject1, GameObject* gameObject2, const char* Type);
		bool GameObjectKillSwitch();
		bool Collected = false;

	private:
		int x = 1300;
		int y;


};

