#include "Level1.h"
#include "Game.h"

void Level1::RenderLevel()
{
	DrawTexture(Background, xPostBackground, 0, WHITE);
	DrawTexture(Background, xPostBackground2, 0, WHITE);

	DrawText(TextFormat("Score: %d", (int)score), 0, 0, 30, RAYWHITE);
	DrawText(TextFormat("Packages: %d", Packages), 0, 80, 30, RAYWHITE);


	DrawTexture(Ground, 0, (720 - 100), WHITE);
}

void Level1::LevelMechanics()
{
	score += 0.01;
	xPostBackground -= 2;
	xPostBackground2 -= 2;
	if (xPostBackground == 0) {
		xPostBackground2 = 1600;
	}
	if (xPostBackground2 == 0) {
		xPostBackground = 1600;	
	}
}

void Level1::LoadTextures()
{
	Background = LoadTexture("./assets/background.png");
	Ground = LoadTexture("./assets/ground.png");
}

void Level1::UnLoadTextures()
{
	UnloadTexture(Background);
	UnloadTexture(Ground);
}
