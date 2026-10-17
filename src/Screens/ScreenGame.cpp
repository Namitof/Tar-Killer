#include "ScreenGame.h"

#include "../Objects/Player.h"
#include "../Objects/ColisionManager.h"

#include <raylib.h>

namespace Game
{
	static Player::Player player;

	void Init()
	{
		Player::Init(player);
	}

	void Update(float deltaTime, int width, int height)
	{
		Player::Update(player, deltaTime);
		ColisionManager::CheckColisions(player, width, height);
		
	}

	void Draw()
	{
		Player::Draw(player);
	}

	void Delete()
	{

	}
}