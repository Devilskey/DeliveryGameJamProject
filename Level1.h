#include "LevelObject.h"
#include "raylib.h"
#pragma once
class Level1 : public LevelObject
{
public:
	void RenderLevel();
	void LevelMechanics();
	void LoadTextures();
	void UnLoadTextures();

private:
	int xPostBackground2 = 1280;
	Texture2D Background2;
	int xPostBackground = 0;
	Texture2D Background;
	Texture2D Ground;
};
