#include "ScreenGame.h"

#include <raylib.h>

#include "../Objects/Player.h"
#include "../Objects/Bullet.h"
#include "../Objects/ColisionManager.h"

namespace Game
{
	//Constantes
	static Player::Player player;

	static Bullet::Bullet bulletPool[Bullet::MAX_BULLETS];

	void Init()
	{
		Player::Init(player);

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