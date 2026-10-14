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
		player.speed = 0.0f;
	}

	void Update(Player& player, float deltaTime)
	{
		player.direction.x = GetMouseX() - player.pos.x;
		player.direction.y = GetMouseY() - player.pos.y;

		float magnitude = sqrt((player.direction.x * player.direction.x) + (player.direction.y * player.direction.y));

		magnitude = abs(magnitude);

		if (magnitude < PLAYER_MIN_DISTANCE)
		{
			magnitude = PLAYER_MIN_DISTANCE;
		}
		else if (magnitude > PLAYER_MAX_DISTANCE)
		{
			magnitude = PLAYER_MAX_DISTANCE;
		}

		player.speed = PLAYER_MIN_SPEED + ((magnitude/PLAYER_MAX_DISTANCE) * (PLAYER_MAX_SPEED - PLAYER_MIN_SPEED));

		player.direction = Vector2Normalize(player.direction);

	}

	void Draw(Player player)
	{
		DrawCircle(player.pos.x, player.pos.y, player.radius, RED);
	}

	void Move(Player& player, float deltaTime)
	{
		player.pos.x += player.direction.x * deltaTime * player.speed;
		player.pos.y += player.direction.y * deltaTime * player.speed;

		player.speed -= 0.005f;

		if (player.speed < 0)
		{
			player.speed = 0;
		}

	}

}