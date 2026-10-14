#include "Player.h"

#include <raylib.h>
#include <raymath.h>
#include <cmath>

namespace Player
{


	void Init(Player& player)
	{
		player.pos.x = 50.0f;
		player.pos.y = 50.0f;

		player.direction.x = 0.0f;
		player.direction.y = 0.0f;

		player.radius = PLAYER_RADIUS;

		player.maxSpeed = PLAYER_MAX_SPEED;
		player.currentSpeed = 0.0f;
		player.acceleration = PLAYER_ACCELERATION;
	}

	void Move(Player& player, float deltaTime)
	{
		player.pos.x += player.direction.x * deltaTime * player.currentSpeed;
		player.pos.y += player.direction.y * deltaTime * player.currentSpeed;
	}

	void Accelerate(Player& player)
	{
		player.currentSpeed += player.acceleration;

		if (player.currentSpeed > player.maxSpeed)
		{
			player.currentSpeed = player.maxSpeed;
		}
	}

	void SlowDown(Player& player)
	{
		player.currentSpeed -= player.acceleration;

		if (player.currentSpeed < 0)
		{
			player.currentSpeed = 0;
		}
	}

	void Update(Player& player, float deltaTime)
	{
		//Actualizo vector direccion
		player.direction.x = static_cast<float>(GetMouseX()) - player.pos.x;
		player.direction.y = static_cast<float>(GetMouseY()) - player.pos.y;
		player.direction = Vector2Normalize(player.direction);

		Move(player, deltaTime);
		
	}

	void Draw(Player player)
	{
		DrawCircleV(player.pos, player.radius, RED);
	}

}