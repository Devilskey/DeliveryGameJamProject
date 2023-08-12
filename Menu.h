#include "LevelObject.h"
#include "raylib.h"
#include "Game.h"
#pragma once
class Menu : public LevelObject
{
public:
	void RenderLevel();
	void LevelMechanics();
	void LoadTextures();
	void unLoadTextures();

private:
	Texture2D Background;
	Texture2D Ground;
	Texture2D Van;
};
