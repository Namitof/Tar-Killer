#include "ScreenGame.h"

#include <raylib.h>

#include "../Objects/Player.h"
#include "../Objects/Bullet.h"
#include "../Objects/ColisionManager.h"
#include "../Utils/Sprite.h"

namespace Game
{
	//Constantes

	static Sprite::Sprite background;

	static Player::Player player;

	static Bullet::Bullet bulletPool[Bullet::MAX_BULLETS];


	void BackgroundInit(Texture2D gameBackground, int screenWidth, int screenHeight);

	void PlayerInit(Texture2D playerTexture, int screenWidth, int screenHeight);


	void BackgroundInit(Texture2D gameBackground, int screenWidth, int screenHeight)
	{
		//Componentes del struct sprite
		Rectangle source;
		Rectangle destination;
		Vector2 pivot;
		float rotation;
		Color tint;

		//Init a background
		source.x = 0.0f;
		source.y = 0.0f;
		source.width = static_cast<float>(gameBackground.width);
		source.height = static_cast<float>(gameBackground.height);

		destination.x = 0.0f;
		destination.y = 0.0f;
		destination.width = static_cast<float>(screenWidth);
		destination.height = static_cast<float>(screenHeight);

		pivot.x = 0.0f;
		pivot.y = 0.0f;

		rotation = 0;

		tint = WHITE;

		Sprite::Init(background, gameBackground, source, destination, pivot, rotation, tint);
	}

	void PlayerInit(Texture2D playerTexture, int screenWidth, int screenHeight)
	{
		Sprite::Sprite playerSprite;

		//Componentes del struct sprite
		Rectangle source;
		Rectangle destination;
		Vector2 pivot;
		float rotation;
		Color tint;

		//Init a background
		source.x = 0.0f;
		source.y = 0.0f;
		source.width = static_cast<float>(playerTexture.width);
		source.height = static_cast<float>(playerTexture.height);

		destination.x = 0.0f;
		destination.y = 0.0f;
		destination.width = static_cast<float>(Player::PLAYER_RADIUS * 2);
		destination.height = static_cast<float>(Player::PLAYER_RADIUS * 2);

		pivot.x = 0.0f;
		pivot.y = 0.0f;

		rotation = 0;

		tint = WHITE;

		Sprite::Init(playerSprite, playerTexture, source, destination, pivot, rotation, tint);

		Player::Init(player, playerSprite, screenWidth, screenHeight);
	}

	void Init(Texture2D gameBackground, int screenWidth, int screenHeight, Texture2D playerTexture)
	{
		BackgroundInit(gameBackground, screenWidth, screenHeight);

		PlayerInit(playerTexture, screenWidth, screenHeight);

		for (int i = 0; i < Bullet::MAX_BULLETS; i++)
		{
			Bullet::Init(bulletPool[i]);
		}

	}

	void Update(float deltaTime, int width, int height)
	{
		Player::Update(player, deltaTime);

		if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
		{
			for (int i = 0; i < Bullet::MAX_BULLETS; i++)
			{
				if (!bulletPool[i].isActive)
				{
					bulletPool[i].isActive = true;
					Bullet::SetPos(bulletPool[i], player.pos);
					Bullet::SetDirection(bulletPool[i], player.direction);
					break;
				}
			}
		}

		for (int i = 0; i < Bullet::MAX_BULLETS; i++)
		{
			Bullet::Update(bulletPool[i], deltaTime);
		}

		ColisionManager::CheckColisions(player, bulletPool, width, height);

	}

	void Draw()
	{
		Sprite::Draw(background);

		for (int i = 0; i < Bullet::MAX_BULLETS; i++)
		{
			if (bulletPool[i].isActive)
			{
				Bullet::Draw(bulletPool[i]);
			}
		}

		Player::Draw(player);

	}
}

//Centrar nave en el centro

//Pausa y HUD