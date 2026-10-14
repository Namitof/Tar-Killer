#include "ScreenGame.h"
#include "../Objects/Player.h"

#include <raylib.h>

namespace Game
{
	static Player::Player player;

	void Init()
	{
		Player::Init(player);
	}

	void Update(float deltaTime)
	{
		Player::Update(player, deltaTime);

		if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
		{
			Player::Accelerate(player);

		}
		else
		{
			Player::SlowDown(player);
		}
	}

	void Draw()
	{
		Player::Draw(player);
	}
}