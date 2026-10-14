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
		Player::Move(player, deltaTime);

		if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
		{
			Player::Update(player, deltaTime);
		}
	}

	void Draw()
	{
		Player::Draw(player);
	}
}