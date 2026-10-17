#pragma once
#include "Player.h"

namespace ColisionManager
{
	void ScreenBorderCollision(float& posX, float& posY, float radius, int width, int height);

	void CheckColisions(Player::Player& player, int width, int height);
}
