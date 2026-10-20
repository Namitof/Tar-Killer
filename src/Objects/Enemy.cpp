#include "Enemy.h"

#include <raylib.h>
#include <raymath.h>

namespace Enemy
{
	
	void InitSmallEnemy(Enemy& currentEnemy)
	{
		currentEnemy.radius = ENEMY_SMALL_RADIUS;
		currentEnemy.speed = ENEMY_SMALL_SPEED;
		currentEnemy.sprite;
		currentEnemy.size = EnemySize::Small;

	}

	void InitMediumEnemy(Enemy& currentEnemy)
	{
		currentEnemy.radius = ENEMY_MEDIUM_RADIUS;
		currentEnemy.speed = ENEMY_MEDIUM_SPEED;
		currentEnemy.sprite;
		currentEnemy.size = EnemySize::Medium;

	}

	void InitLargeEnemy(Enemy& currentEnemy)
	{
		currentEnemy.radius = ENEMY_LARGE_RADIUS;
		currentEnemy.speed = ENEMY_LARGE_SPEED;
		currentEnemy.sprite;
		currentEnemy.size = EnemySize::Large;

	}

	void Init(Enemy& currentEnemy, EnemySize enemySize)
	{
		currentEnemy.pos.x = -1.0f;
		currentEnemy.pos.y = -1.0f;

		currentEnemy.direction.x = 0.0f;
		currentEnemy.direction.y = 0.0f;

		currentEnemy.isActive = false;
		currentEnemy.tint = WHITE;

		//currentEnemy.type;

		switch (enemySize)
		{
		case EnemySize::Small:
			InitSmallEnemy(currentEnemy);
			break;
		case EnemySize::Medium:
			InitMediumEnemy(currentEnemy);
			break;
		case EnemySize::Large:
			InitLargeEnemy(currentEnemy);
			break;
		default:
			break;
		}

	}

	void Update(Enemy& currentEnemy, float deltaTime)
	{
		currentEnemy.pos.x += currentEnemy.direction.x * currentEnemy.speed * deltaTime;
		currentEnemy.pos.y += currentEnemy.direction.x * currentEnemy.speed * deltaTime;
	}

	void Draw(Enemy currentEnemy)
	{
		DrawCircleV(currentEnemy.pos, currentEnemy.radius, currentEnemy.tint);
	}

	void SetDireccion(Enemy& currentEnemy, Vector2 direction)
	{
		currentEnemy.direction = Vector2Normalize(direction);
	}

	void SetPos(Enemy& currentEnemy, Vector2 pos)
	{
		currentEnemy.pos = pos;
	}
}