#include "Bullet.h"

#include <raylib.h>
#include <raymath.h>

#include "Utils/Sprite.h"

namespace Bullet
{
	static Sprite::Sprite bullet;

	void Init(Bullet& currentBullet)
	{
		currentBullet.pos.x = -1;
		currentBullet.pos.y = -1;

		currentBullet.radius = BULLET_RADIUS;

		currentBullet.direction.x = 0;
		currentBullet.direction.y = 0;

		currentBullet.speed = BULLET_SPEED;

		currentBullet.isActive = false;

		currentBullet.count = 0.0f;
		currentBullet.countMaxValue = COUNT_MAX_VALUE;

		currentBullet.tint = BULLET_COLOR;

		currentBullet.sprite = bullet;
	}

	void Update(Bullet& currentBullet, float deltaTime)
	{
		if (!currentBullet.isActive)
			return;

		//Actualizar posicion
		currentBullet.pos.x += currentBullet.direction.x * currentBullet.speed * deltaTime;
		currentBullet.pos.y += currentBullet.direction.y * currentBullet.speed * deltaTime;

		currentBullet.sprite.destination.x = currentBullet.pos.x;
		currentBullet.sprite.destination.y = currentBullet.pos.y;

		//Actualizar el contador
		currentBullet.count += deltaTime;
		if (currentBullet.count >= currentBullet.countMaxValue)
		{
			Init(currentBullet);
		}

	}

	void Draw(Bullet currentBullet)
	{
#ifdef _DEBUG
		DrawCircleV(currentBullet.pos, currentBullet.radius, currentBullet.tint);
#endif // _DEBUG
		Sprite::Draw(currentBullet.sprite);
	}

	void SetDirection(Bullet& currentBullet, Vector2 direction)
	{
		currentBullet.direction = Vector2Normalize(direction);
	}

	void SetPos(Bullet& currentBullet, Vector2 pos)
	{
		currentBullet.pos = pos;
	}

	void AddBulletInPool(Bullet bulletPool[MAX_BULLETS], Vector2 pos, Vector2 dir, float angle)
	{
		for (int i = 0; i < MAX_BULLETS; i++)
		{
			if (!bulletPool[i].isActive)
			{
				Init(bulletPool[i]);
				bulletPool[i].isActive = true;
				bulletPool[i].sprite.rotation = angle;
				SetPos(bulletPool[i], pos);
				SetDirection(bulletPool[i], dir);
				break;
			}
		}
	}

	void SetSprite(Texture2D spriteBullet)
	{
		//Componentes del struct sprite
		Rectangle source;
		Rectangle destination;
		Vector2 pivot;
		float rotation;
		Color tint;

		//Init
		source.x = 0.0f;
		source.y = 0.0f;
		source.width = static_cast<float>(spriteBullet.width);
		source.height = static_cast<float>(spriteBullet.height);

		destination.x = 0;
		destination.y = 0;
		destination.width = static_cast<float>(BULLET_RADIUS * 2);
		destination.height = static_cast<float>(BULLET_RADIUS * 2);

		pivot.x = destination.width / 2;
		pivot.y = destination.height / 2;

		rotation = 0;

		tint = WHITE;

		Sprite::Init(bullet, spriteBullet, source, destination, pivot, rotation, tint);
	}
}