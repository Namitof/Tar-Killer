#include "Button.h"

#include <raylib.h>

#include "Utils/Text.h"
#include "Utils/Sprite.h"

namespace Button
{
	void Init(Button& currentButton, Color buttonColor, Color selectColor, Rectangle hitbox, Text::Text text, Sprite::Sprite defaultSprite, Sprite::Sprite selectSprite)
	{
		currentButton.isPressed = false;
		currentButton.wasPressed = false;
		currentButton.isMouseOnButton = false;

		currentButton.soundIsPlaying = false;

		currentButton.currentColor = buttonColor;
		currentButton.defaultColor = buttonColor;
		currentButton.selectColor = selectColor;

		currentButton.hitbox = hitbox;

		currentButton.text = text;

		currentButton.defaultSprite = defaultSprite;
		currentButton.currentSprite = defaultSprite;
		currentButton.selectSprite = selectSprite;
	}

	void Update(Button& currentButton, Vector2 mousePosition)
	{
		currentButton.wasPressed = currentButton.isPressed;

		double minX = currentButton.hitbox.x;
		double minY = currentButton.hitbox.y;
		double maxX = currentButton.hitbox.x + currentButton.hitbox.width;
		double maxY = currentButton.hitbox.y + currentButton.hitbox.height;

		if ((mousePosition.x >= minX && mousePosition.x <= maxX) && (mousePosition.y >= minY && mousePosition.y <= maxY))
		{
			currentButton.isMouseOnButton = true;
			currentButton.currentColor = currentButton.selectColor;
			currentButton.currentSprite = currentButton.selectSprite;
		}
		else
		{
			currentButton.isMouseOnButton = false;

			currentButton.soundIsPlaying = false;

			currentButton.currentColor = currentButton.defaultColor;
			currentButton.currentSprite = currentButton.defaultSprite;

		}

		if (currentButton.isMouseOnButton && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		{
			currentButton.isPressed = true;
		}
		else
		{
			currentButton.isPressed = false;
		}

	}

	void Draw(Button currentButton)
	{
		//Hitbox
#ifdef _DEBUG
		DrawRectangleRec(currentButton.hitbox, RED);
#endif
		//Boton
		Sprite::Draw(currentButton.currentSprite);
		Text::Draw(currentButton.text);
	}

}

