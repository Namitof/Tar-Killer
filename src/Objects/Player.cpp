#include "Player.h"

#include <cmath>

#include <raylib.h>
#include <raymath.h>

#include "Utils/Sprite.h"
#include "Screens/AudioManager.h"

namespace Player
{
	void Init(Player& player, Sprite::Sprite playerSprite, int screenWidth, int screenHeight)
	{
		player.pos.x = static_cast<float>(screenWidth / 2);
		player.pos.y = static_cast<float>(screenHeight / 2);

		player.direction.x = 0.0f;
		player.direction.y = 0.0f;

		player.speed.x = 0.0f;
		player.speed.y = 0.0f;

		player.radius = PLAYER_RADIUS;

		player.maxSpeed = PLAYER_MAX_SPEED;

		player.spriteRectangle.width = PLAYER_RADIUS * 2;
		player.spriteRectangle.height = PLAYER_RADIUS * 2;
		player.spriteRectangle.x = player.pos.x;
		player.spriteRectangle.y = player.pos.y;

		player.pivot.x = player.spriteRectangle.width / 2;
		player.pivot.y = player.spriteRectangle.height / 2;

		player.rotation = 0.0f;

		player.lifes = PLAYER_LIFES;
		player.score = 0;

		player.sprite = playerSprite;

		player.sprite.pivot = player.pivot;
		player.sprite.destination = player.spriteRectangle;

		player.isImmortal = false;
		player.count = 0.0f;;
		player.maxCount = MAX_DURATION_IMMORTALITY;
	}

	void Move(Player& player, float deltaTime)
	{
		player.pos.x += player.speed.x * deltaTime;
		player.pos.y += player.speed.y * deltaTime;

		player.spriteRectangle.x = player.pos.x;
		player.spriteRectangle.y = player.pos.y;

		player.sprite.destination.x = player.spriteRectangle.x;
		player.sprite.destination.y = player.spriteRectangle.y;

	}

	void CalculateNewAngle(Player& player, Vector2 posMouse)
	{
		float angle = atan(player.direction.y / player.direction.x);

		angle *= RAD2DEG;

		//if (posMouse.x > player.pos.x && posMouse.y < player.pos.y)
		//{
		//	//Cuadrante 1
		//	angle += 0;
		//}
		//else if (posMouse.x < player.pos.x && posMouse.y < player.pos.y)
		//{
		//	//Cuadrante 2
		//	angle += 180;
		//}
		//else if (posMouse.x < player.pos.x && posMouse.y > player.pos.y)
		//{
		//	//Cuadrante 3
		//	angle += 180;
		//}
		//else if (posMouse.x > player.pos.x && posMouse.y > player.pos.y)
		//{
		//	//Cuadrante 4
		//	angle += 360;
		//}

		if ((posMouse.x < player.pos.x && posMouse.y < player.pos.y) || (posMouse.x < player.pos.x && posMouse.y > player.pos.y))
		{
			//Cuadrante 2 o 3
			angle += 180;
		}
		else if (posMouse.x > player.pos.x && posMouse.y >  player.pos.y)
		{
			//Cuadrante 4
			angle += 360;
		}

		player.rotation = angle;

		player.sprite.rotation = player.rotation;
	}

	void Update(Player& player, float deltaTime)
	{
		// Actualizo vector direccion
		Vector2 posMouse = GetMousePosition();
		player.direction = Vector2Subtract(posMouse, player.pos);

		// Calculo el nuevo angulo
		CalculateNewAngle(player, posMouse);

		// Aceleracion
		if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
		{
			AudioManager::PlayPlayerMoveSound();

			player.direction = Vector2Normalize(player.direction);

			player.speed.x += (player.direction.x * player.maxSpeed) * deltaTime;
			player.speed.y += (player.direction.y * player.maxSpeed) * deltaTime;

			float magnitude = Vector2Length(player.speed);

			if (magnitude > player.maxSpeed)
			{
				player.speed.x = (player.speed.x / magnitude) * player.maxSpeed;
				player.speed.y = (player.speed.y / magnitude) * player.maxSpeed;
			}
		}

		Move(player, deltaTime);
	}

	void Draw(Player player)
	{
#ifdef _DEBUG
		DrawRectanglePro(player.spriteRectangle, player.pivot, player.rotation, BLUE);
		DrawCircleV(player.pos, player.radius, RED);
#endif
		Sprite::Draw(player.sprite);
	}
}