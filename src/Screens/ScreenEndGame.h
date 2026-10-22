#pragma once

#pragma once

#include <raylib.h>

namespace EndGame
{
	void Init(Font font, Texture2D defaultButtonTexture, Texture2D selectButtonTexture, int screenWidth, int screenHeight, Sound selectSound);

	void Update(bool& exitButtonPressed, bool& retryButtonPressed);

	void Draw();
}