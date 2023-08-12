#include "Menu.h"

void Menu::RenderLevel()
{
	DrawTexture(Background, 0, 0, WHITE);
	DrawTexture(Ground, 0, (720 - 100), WHITE);
	DrawTexture(Van, 606, 500, WHITE);
	DrawText("DeliveryGame", 400, 0, 60, RAYWHITE);
	DrawText("Press Space to play", 400, 60, 40, RAYWHITE);
	DrawText(TextFormat("HighScore: %d", highScore), 400, 100, 40, RAYWHITE);
	DrawText(TextFormat("last score: %d", scorevisible), 400, 150, 20, RAYWHITE);

}

void Menu::LevelMechanics()
{
}

void Menu::LoadTextures()
{
	Background = LoadTexture("./assets/background.png");
	Ground = LoadTexture("./assets/ground.png");
	Van = LoadTexture("./assets/platyer.png");
}

void Menu::unLoadTextures()
{
	UnloadTexture(Ground);
	UnloadTexture(Background);
	UnloadTexture(Van);
}
