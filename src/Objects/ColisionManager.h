#pragma once
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

namespace ColisionManager
{
	void ScreenBorderCollision(float& posX, float& posY, float radius, int width, int height, bool playSound);

	void CheckColisions(Player::Player& player, Bullet::Bullet bullets[Bullet::MAX_BULLETS], Enemy::Enemy enemys[Enemy::MAX_ENEMYS], int width, int height, int& enemyCountEliminated);
}
