#include "raylib.h"
#include "screen.cpp"
#include "player.h"
#include "Menu.h"
#include "Level1.h"
#include "ObsticalBox.h"
#include "coin.h"
#include "Package.h"
#include <random>
#include <vector>
#include <iostream>

using namespace std;

bool running = true;
Screen screen;
Player* player;
Level1 level1;
random_device random;
mt19937 gen(random());
uniform_int_distribution<> ObsticalSize(50, 150);

Menu menu;

bool switchScene;
bool IsInMenu;
int ObsticalCounter;
int MinimalObsticals;

int MinimalCoins;
int CoinCounter;

int PackageCounter;

vector<GameObject*> gameObjects;

void Dificulty() {
	if (score < 50) {
		MinimalObsticals = 1;
		MinimalCoins = 1;
	}
	else if (score > 250 && score < 500) {
		MinimalObsticals = 2;
		MinimalCoins = 2;
	}
	else if (score > 500 && score < 2000) {
		MinimalObsticals = 3;
		MinimalCoins = 2;

	}
	else if (score > 2000 && score < 4000) {
		MinimalObsticals = 4;
		MinimalCoins = 3;

	}
	else if (score > 4000 && score < 6000) {
		MinimalObsticals = 5;
		MinimalCoins = 3;

	}
	else if (score > 6000 && score < 10000) {
		MinimalObsticals = 6;
		MinimalCoins = 2;

	}
	else if (score > 10000 && score < 15000) {
		MinimalObsticals = 8;
		MinimalCoins = 2;

	}
	else if (score > 15000) {
		MinimalObsticals = 10;
		MinimalCoins = 2;
	}
};

int main() {
	screen.InitializeScreen();
	menu.LoadTextures();
	screen.levelLoader.switchLevel(&menu);
	IsInMenu = true;

	while (running) {
		Dificulty();
		if (!IsInMenu && switchScene) {
			screen.levelLoader.switchLevel(&level1);
			player = new Player();
			player->LoadTextures();
			menu.unLoadTextures();
			level1.LoadTextures();
			gameObjects.push_back(player);
			switchScene = false;
		}
		if (IsInMenu && switchScene) {
			level1.UnLoadTextures();
			menu.LoadTextures();
			gameObjects.clear();
			screen.levelLoader.switchLevel(&menu);
			switchScene = false;
		}
		if (IsInMenu) {
			if (GetKeyPressed() == KEY_SPACE) {
				IsInMenu = false;
				switchScene = true;
			}
		}
		if (GameOver) {
			IsInMenu = true;
			switchScene = true;
			scorevisible = score;
			if (score > highScore) {
				highScore = score;
				score = 0;
			}
			GameOver = false;
		}

		screen.Render(gameObjects);
		for (int i = 0; i < gameObjects.size(); i++) {
			gameObjects[i]->ObjectFunction();
			if (gameObjects[i]->type == "ObsticalBox")
				ObsticalCounter++;

			if (gameObjects[i]->type == "coin")
				CoinCounter++;

			if (gameObjects[i]->type == "package")
				PackageCounter++;

			for (int j = 0; j < gameObjects.size(); j++) {
				gameObjects[i]->CheckCollisions(gameObjects[i], gameObjects[j], gameObjects[j]->type);
			}
			if (gameObjects[i]->GameObjectKillSwitch()) {
				delete gameObjects[i];
				gameObjects.erase(gameObjects.begin() + i);

			}
		}
		if (!IsInMenu) {
			if (CoinCounter < MinimalCoins) {
				coin* newCoin = new coin();
				gameObjects.push_back(newCoin);
			}
			else {
				CoinCounter = 0;
			}
			if (PackageCounter < 1) {
				Package* newPackage = new Package();
				gameObjects.push_back(newPackage);
			}
			else {
				PackageCounter = 0;
			}

			if (ObsticalCounter < MinimalObsticals) {
				int WidthObstical = ObsticalSize(gen);
				int heightObstical = ObsticalSize(gen);
				ObsticalBox* newObstical = new ObsticalBox(WidthObstical, heightObstical);
				gameObjects.push_back(newObstical);
			}
			else {
				ObsticalCounter = 0;
			}
		}
	}
}
