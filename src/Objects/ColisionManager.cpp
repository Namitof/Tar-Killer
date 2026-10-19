#include "ColisionManager.h"

#include "Player.h"

#include "Bullet.h"

namespace ColisionManager
{
	void ScreenBorderCollision(float& posX, float& posY, float radius, int width, int height)
	{
		const int MIN_POS_X = 0;
		const int MIN_POS_Y = 0;

		// Chequeo colision de player con los bordes de la pantalla
		if (posX + radius < MIN_POS_X)
		{
			posX = width + radius;
		}
		else if (posX - radius > width)
		{
			posX = MIN_POS_X - radius;
		}

		if (posY + radius < MIN_POS_Y)
		{
			posY = height + radius;
		}
		else if (posY - radius > height)
		{
			posY = MIN_POS_Y - radius;
		}
	}

	void CheckColisions(Player::Player& player, Bullet::Bullet bullets[Bullet::MAX_BULLETS], int width, int height)
	{
		// Chequeo colision de player con los bordes de la pantalla
		ScreenBorderCollision(player.pos.x, player.pos.y, player.radius, width, height);

		// Chequeo colision de player con los bordes de la pantalla
		for (int i = 0; i < Bullet::MAX_BULLETS; i++)
		{
			if (bullets[i].isActive)
			{
				ScreenBorderCollision(bullets[i].pos.x, bullets[i].pos.y, bullets[i].radius, width, height);
			}
		}


		// Chequeo colision del player con los enemigos

		// Chequeo colision de las balas con los obstaculos

	}
}
