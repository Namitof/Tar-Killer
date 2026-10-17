#include "ColisionManager.h"

#include "Player.h"

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

	void CheckColisions(Player::Player& player, int width, int height)
	{
		// Chequeo colision de player con los bordes de la pantalla
		ScreenBorderCollision(player.pos.x, player.pos.y, player.radius, width, height);

		// Chequeo colision del player con los enemigos

		// Chequeo colision de las balas con los obstaculos

	}
}
