#pragma once

#include <raylib.h>

namespace Game
{
	//Constantes

	const float BUTTON_OFFSET = 20.0f;


	void Init(Texture2D gameBackground, int screenWidth, int screenHeight, Texture2D playerTexture, Font font, Texture2D defaultButtonTexture, Texture2D selectButtonTexture, Sound selectSound);

	void Update(bool& pauseButtonPressed, bool& isGameOver, float deltaTime, int width, int height);

	void Draw();
}