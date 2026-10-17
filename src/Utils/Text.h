#pragma once
#include <string>

#include <raylib.h>


struct Text
{
	Font font;
	float fontSize;
	std::string text;
	Vector2 position;
	float spacing;
	Color tint;
};

void TextInit(Text& currentText, Font font, float fontSize, std::string text, Vector2 position, float spacing, Color tint);

void SetTextPos(Text& currentText, float textPosX, float textPosY);

void DrawText(Text& currentText);