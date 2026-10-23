#pragma once

#include <raylib.h>

namespace EndGame
{
	void Init(Font font, Texture2D defaultButtonTexture, Texture2D selectButtonTexture, int screenWidth, int screenHeight);

	void Update(bool& exitButtonPressed, bool& retryButtonPressed, int playerScore);

	void Draw();
}