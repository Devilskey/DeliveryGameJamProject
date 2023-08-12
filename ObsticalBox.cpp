#include "ObsticalBox.h"

void ObsticalBox::ForceBack()
{
	x -= speed;
}

void ObsticalBox::RenderObject()
{
	DrawRectangle(x, y, width, height, BROWN);
	object = { (float)x, (float)y, (float)width, (float)height };
}

bool ObsticalBox::GameObjectKillSwitch()
{
	if (x < -120 && x > -200) {
		score += 5;
		return true;
	}
	else if (x < -200) {
		return true;
	}
	return false;
}
