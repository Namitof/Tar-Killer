#pragma once

#include <raylib.h>

#include "../Utils/Text.h"
#include "../Utils/Sprite.h"

namespace Button
{
	const double BUTTON_WIDTH = 250;
	const double BUTTON_HEIGHT = 80;

	struct Button
	{
		bool isPressed;
		bool wasPressed;
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

	void ButtonInit(Button& currentButton, Color buttonColor, Color selectColor, Rectangle hitbox, Vector2 position, Sprite::Sprite defaultSprite, Sprite::Sprite selectSprite);

	void IsMouseOnButton(Button& currentButton, Vector2 mousePosition);

	void DrawButton(Button currentButton);
}

