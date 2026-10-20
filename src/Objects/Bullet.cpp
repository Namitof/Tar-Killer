#include "Bullet.h"

#include <raylib.h>
#include <raymath.h>

namespace Bullet
{
	void Init(Bullet& currentBullet)
	{
		currentBullet.pos.x = -1;
		currentBullet.pos.x = -1;

		currentBullet.radius = BULLET_RADIUS;

		currentBullet.direction.x = 0;
		currentBullet.direction.y = 0;

		currentBullet.speed = BULLET_SPEED;

		currentBullet.isActive = false;

		currentBullet.count = 0.0f;
		currentBullet.countMaxValue = COUNT_MAX_VALUE;

		currentBullet.tint = BULLET_COLOR;
	}

	void Update(Bullet& currentBullet, float deltaTime)
	{
		if (!currentBullet.isActive)
			return;

		//Actualizar posicion
		currentBullet.pos.x += currentBullet.direction.x * currentBullet.speed * deltaTime;
		currentBullet.pos.y += currentBullet.direction.y * currentBullet.speed * deltaTime;

		//Actualizar el contador
		currentBullet.count += deltaTime;
		if (currentBullet.count >= currentBullet.countMaxValue)
		{
			Init(currentBullet);
		}

	}

	void Draw(Bullet currentBullet)
	{
		DrawCircleV(currentBullet.pos, currentBullet.radius, currentBullet.tint);
	}

	void SetDirection(Bullet& currentBullet, Vector2 direction)
	{
		currentBullet.direction = Vector2Normalize(direction);
	}

	void SetPos(Bullet& currentBullet, Vector2 pos)
	{
		currentBullet.pos = pos;
	}
}