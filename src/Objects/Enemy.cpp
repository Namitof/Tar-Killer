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

	Vector2 GenerateRandomDirection()
	{
		Vector2 direction;

		//Constantes
		const int MAX_ANGLE = 36000;
		const int MIN_ANGLE = 0;
		const float DIVISION = 100.0f;

		int randomNumber = GetRandomValue(MIN_ANGLE, MAX_ANGLE);

		float angle = randomNumber / DIVISION;

		angle *= DEG2RAD;

		float x = static_cast<float>(cos(angle));
		float y = static_cast<float>(sin(angle));

		direction.x = x;
		direction.y = y;

		return direction;
	}

	Vector2 GenerateRandomPosition()
	{
		Vector2 position;

		//Constantes
		const int MIN_POS = 0;
		const int MAX_POS = 768;

		//const Vector2 MIN_POS = {-50.0f, 0.0f};
		//const Vector2 MAX_POS = {-50.0f, 768.0f};
		//const float DIVISION = 100.0f;

		int randomNumber = GetRandomValue(MIN_POS, MAX_POS);

		position.x = -50.0f;
		position.y = static_cast<float>(randomNumber);

		return position;
	}

	void AddEnemyInPool(Enemy enemyPool[MAX_ENEMYS], EnemySize size, Vector2 spawnPos, Vector2 direction)
	{
		for (int i = 0; i < MAX_ENEMYS; i++)
		{
			if (!enemyPool[i].isActive)
			{
				Init(enemyPool[i], size);
				SetPos(enemyPool[i], spawnPos);
				SetDireccion(enemyPool[i], direction);

				enemyPool[i].isActive = true;

				break;
			}
		}
	}
}