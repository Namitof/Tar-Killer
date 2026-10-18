#pragma once

#include <raylib.h>

namespace Credits
{
	void Init(Texture2D menuBackground, Font font, Texture2D defaultButtonTexture, Texture2D selectButtonTexture, int screenWidth, int screenHeight);

	void Update(bool& backButtonPressed);

	void Draw();
}