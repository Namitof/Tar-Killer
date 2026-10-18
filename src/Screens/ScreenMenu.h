#pragma once

#include <raylib.h>

namespace Menu
{
	const float LOGO_POS_X = 50.0f;
	const float LOGO_POS_Y = 50.0f;

	const Vector2 INITIAL_BUTTON_POS = { 700.0f, 300.0f };
	
	const float BUTTON_OFFSET = 10.0f;

	void Init(Texture2D menuBackground, Texture2D logoTexture, Font font, Texture2D defaultButtonTexture, Texture2D selectButtonTexture, int screenWidth, int screenHeight);

	void Update(bool& playButtonPressed, bool& settingsButtonPressed, bool& rulesButtonPressed, bool& creditsButtonPressed, bool& exitButtonPressed);

	void Draw();
}