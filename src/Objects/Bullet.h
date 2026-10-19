#pragma once

#include <raylib.h>

namespace Bullet
{
	//Constantes
	const int MAX_BULLETS = 100;

	const float BULLET_SPEED = 500.0f;

	const float COUNT_MAX_VALUE = 5.0f;

	const float BULLET_RADIUS = 30.0f;

	const Color BULLET_COLOR = VIOLET;

	struct Bullet
	{
		Vector2 pos;
		float radius;
		Vector2 direction;
		float speed;
		bool isActive;
		float count;
		float countMaxValue;
		Color tint;
	};

	void Init(Bullet& currentBullet);

	void Update(Bullet& currentBullet, float deltaTime);

	void Draw(Bullet currentBullet);

	void SetDirection(Bullet& currentBullet, Vector2 direction);

	void SetPos(Bullet& currentBullet, Vector2 pos);
}