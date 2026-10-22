#pragma once

#include <raylib.h>

#include "Utils/Sprite.h"

namespace Enemy
{
	const int MAX_ENEMYS = 200;

	const float ENEMY_SMALL_RADIUS = 30.0f;

	const float ENEMY_MEDIUM_RADIUS = 40.0f;

	const float ENEMY_LARGE_RADIUS = 50.0f;

	const float ENEMY_SMALL_SPEED = 180.0f;

	const float ENEMY_MEDIUM_SPEED = 100.0f;

	const float ENEMY_LARGE_SPEED = 80.0f;

	const int MAX_LARGE_ENEMY = 28;

	enum class EnemySize
	{
		None = 0,
		Small,
		Medium,
		Large
	};

	enum class EnemyType
	{
		None = 0,
		Simple,
		Focus
	};

	struct Enemy
	{
		Vector2 pos;

		float radius;

		Vector2 direction;

		float speed;

		bool isActive;

		Color tint;

		Sprite::Sprite sprite;

		EnemySize size;

		EnemyType type;
	};



	void InitSmallEnemy(Enemy& currentEnemy);

	void InitMediumEnemy(Enemy& currentEnemy);
	
	void InitLargeEnemy(Enemy& currentEnemy);

	void Init(Enemy& currentEnemy, EnemySize enemySize);

	void Update(Enemy& currentEnemy, float deltaTime);

	void Draw(Enemy currentEnemy);

	void SetDireccion(Enemy& currentEnemy, Vector2 direction);

	void SetPos(Enemy& currentEnemy, Vector2 pos);

	Vector2 GenerateRandomDirection();

	Vector2 GenerateRandomPosition();

	void AddEnemyInPool(Enemy enemyPool[MAX_ENEMYS], EnemySize size, Vector2 spawnPos, Vector2 direction);

	void SetAllSprites(Texture2D largeSprite, Texture2D mediumSprite, Texture2D smallSprite);
}