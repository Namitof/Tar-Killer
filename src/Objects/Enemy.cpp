#include "Enemy.h"

#include <raylib.h>
#include <raymath.h>

#include "Utils/Sprite.h"

namespace Enemy
{
	static Sprite::Sprite enemyLargeSprite;
	static Sprite::Sprite enemyMediumSprite;
	static Sprite::Sprite enemySmallSprite;

	void InitSmallEnemy(Enemy& currentEnemy)
	{
		currentEnemy.radius = ENEMY_SMALL_RADIUS;
		currentEnemy.speed = ENEMY_SMALL_SPEED;
		currentEnemy.sprite = enemySmallSprite;
		currentEnemy.size = EnemySize::Small;

	}

	void InitMediumEnemy(Enemy& currentEnemy)
	{
		currentEnemy.radius = ENEMY_MEDIUM_RADIUS;
		currentEnemy.speed = ENEMY_MEDIUM_SPEED;
		currentEnemy.sprite = enemyMediumSprite;
		currentEnemy.size = EnemySize::Medium;

	}

	void InitLargeEnemy(Enemy& currentEnemy)
	{
		currentEnemy.radius = ENEMY_LARGE_RADIUS;
		currentEnemy.speed = ENEMY_LARGE_SPEED;
		currentEnemy.sprite = enemyLargeSprite;
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
		currentEnemy.pos.y += currentEnemy.direction.y * currentEnemy.speed * deltaTime;

		currentEnemy.sprite.destination.x = currentEnemy.pos.x - currentEnemy.radius;
		currentEnemy.sprite.destination.y = currentEnemy.pos.y - currentEnemy.radius;
	}

	void Draw(Enemy currentEnemy)
	{
#ifdef _DEBUG
		DrawCircleV(currentEnemy.pos, currentEnemy.radius, currentEnemy.tint);
#endif // _DEBUG
		Sprite::Draw(currentEnemy.sprite);
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

	void SetAllSprites(Texture2D largeSprite, Texture2D mediumSprite, Texture2D smallSprite)
	{
		//Componentes del struct sprite
		Rectangle source;
		Rectangle destination;
		Vector2 pivot;
		float rotation;
		Color tint;

		//Init enemy large
		source.x = 0.0f;
		source.y = 0.0f;
		source.width = static_cast<float>(largeSprite.width);
		source.height = static_cast<float>(largeSprite.height);

		destination.x = 0;
		destination.y = 0;
		destination.width = static_cast<float>(ENEMY_LARGE_RADIUS * 2);
		destination.height = static_cast<float>(ENEMY_LARGE_RADIUS * 2);

		pivot.x = 0.0f;
		pivot.y = 0.0f;

		rotation = 0;

		tint = WHITE;

		Sprite::Init(enemyLargeSprite, largeSprite, source, destination, pivot, rotation, tint);


		//Init enemy medium
		source.x = 0.0f;
		source.y = 0.0f;
		source.width = static_cast<float>(mediumSprite.width);
		source.height = static_cast<float>(mediumSprite.height);

		destination.x = 0;
		destination.y = 0;
		destination.width = static_cast<float>(ENEMY_MEDIUM_RADIUS * 2);
		destination.height = static_cast<float>(ENEMY_MEDIUM_RADIUS * 2);

		pivot.x = 0.0f;
		pivot.y = 0.0f;

		rotation = 0;

		tint = WHITE;

		Sprite::Init(enemyMediumSprite, mediumSprite, source, destination, pivot, rotation, tint);


		//Init enemy small
		source.x = 0.0f;
		source.y = 0.0f;
		source.width = static_cast<float>(smallSprite.width);
		source.height = static_cast<float>(smallSprite.height);

		destination.x = 0;
		destination.y = 0;
		destination.width = static_cast<float>(ENEMY_SMALL_RADIUS * 2);
		destination.height = static_cast<float>(ENEMY_SMALL_RADIUS * 2);

		pivot.x = 0.0f;
		pivot.y = 0.0f;

		rotation = 0;

		tint = WHITE;

		Sprite::Init(enemySmallSprite, smallSprite, source, destination, pivot, rotation, tint);
	}

}