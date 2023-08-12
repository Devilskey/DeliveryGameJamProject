#include "Player.h"

bool Player::GameObjectKillSwitch()
{
	if (health <= 0) {
		GameOver = true;
		UnloadTexture(playerSprite);
		return true;
	}
	return false;
}

void Player::Input()
{
	if (IsKeyDown(KEY_W)) {
		y -= (speed + gravityForcePower);
	}
	if (IsKeyDown(KEY_A)) {
		if (x > 0) {
			x -= speed + 3;
		}
	}
	if (IsKeyDown(KEY_D)) {
		if (x < 1280) {
			x += speed;
		}
	}
}

void Player::Gravity()
{
	if (y < (720 - WIDTH - 64)) {
		gravityForce += gravityForcePower * 0.05;
		y += gravityForce;
		grounded = true;
	}
	else
	{
		gravityForce = 0;
		grounded = false;
	}
}

void Player::Checkhealth()
{
	if (health <= 0) {
		health = 0;
		GameOver = true;
		health = 3;
	}
}

void Player::LoadTextures()
{
	playerSprite = LoadTexture("./assets/player.png");
}
