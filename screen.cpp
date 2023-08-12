#include "raylib.h"
#include "GameObject.h"
#include "player.h"
#include <vector>
#include "LevelLoader.cpp"
#include "Game.h"

class Screen {

public:
	LevelLoader levelLoader;

	void InitializeScreen()
	{
		InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
		SetTargetFPS(FPS);
		//int display = GetCurrentMonitor();
		//ToggleFullscreen();
	}

	void Render(vector<GameObject *> gameObjects)
	{
		BeginDrawing();
			ClearBackground(RAYWHITE);
			LevelLoad();
			RenderGameObjects(gameObjects);
		EndDrawing();
	}
	void LevelLoad() {
		levelLoader.RenderLevel();
		levelLoader.useLevelMechanics();
	}

	void RenderGameObjects(vector<GameObject*> gameObjects) {
		for (int i = 0; i < gameObjects.size(); i++) {
			gameObjects[i]->ObjectFunction();
			gameObjects[i]->RenderObject();
		}
	}

private:
	const int SCREEN_WIDTH = 1280;
	const int SCREEN_HEIGHT = 720;
	const char* TITLE = "Delivery";
	const int FPS = 60;
};