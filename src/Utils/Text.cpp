#include "Text.h"

#include <string>

#include <raylib.h>


namespace Text
{
	void Init(Text& currentText, Font font, float fontSize, std::string text, Vector2 position, float spacing, Color tint)
	{
		currentText.font = font;
		currentText.fontSize = fontSize;
		currentText.text = text;
		currentText.position = position;
		currentText.spacing = spacing;
		currentText.tint = tint;
	}

	void SetTextPos(Text& currentText, float textPosX, float textPosY)
	{
		currentText.position.x = textPosX;
		currentText.position.y = textPosY;
	}

	void Draw(Text& currentText)
	{
		DrawTextEx(currentText.font, currentText.text.c_str(), currentText.position, currentText.fontSize, currentText.spacing, currentText.tint);
	}
}

