#pragma once

#include <raylib.h>

namespace Game
{



	void Init(Texture2D gameBackground, int screenWidth, int screenHeight, Texture2D playerTexture);

	void Update(float deltaTime, int width, int height);

	void Draw();
}