#pragma once

#include <raylib.h>

namespace Pause
{
	void Init(Font font, Texture2D defaultButtonTexture, Texture2D selectButtonTexture, int screenWidth, int screenHeight, Sound selectSound);

	void Update(bool& exitButtonPressed, bool& continueButtonPressed);

	void Draw();
}