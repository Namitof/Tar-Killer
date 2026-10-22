#pragma once

#include <raylib.h>

namespace Settings
{
	void Init(Texture2D menuBackground, Font font, Texture2D defaultButtonTexture, Texture2D selectButtonTexture, int screenWidth, int screenHeight, Sound selectSound);

	void Update(bool& backButtonPressed);

	void Draw();
}