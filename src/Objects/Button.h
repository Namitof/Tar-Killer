#pragma once

#include <raylib.h>

#include "../Utils/Text.h"
#include "../Utils/Sprite.h"

namespace Button
{
	const float BUTTON_WIDTH = 250.0f;
	const float BUTTON_HEIGHT = 80.0f;

	struct Button
	{
		bool isPressed;
		bool isMouseOnButton;

		Color currentColor;

		Color defaultColor;

		Color selectColor;

		Text::Text text;

		Rectangle hitbox;

		Sprite::Sprite currentSprite;
		Sprite::Sprite defaultSprite;
		Sprite::Sprite selectSprite;
	};

	void Init(Button& currentButton, Color buttonColor, Color selectColor, Rectangle hitbox, Text::Text text, Sprite::Sprite defaultSprite, Sprite::Sprite selectSprite);

	void Update(Button& currentButton, Vector2 mousePosition);

	void Draw(Button currentButton);
}

