#pragma once
#include "Player.h"
#include "Bullet.h"

namespace ColisionManager
{
	void ScreenBorderCollision(float& posX, float& posY, float radius, int width, int height);

	void CheckColisions(Player::Player& player, Bullet::Bullet bullets[Bullet::MAX_BULLETS], int width, int height);
}
