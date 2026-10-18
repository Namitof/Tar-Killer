#pragma once

#include <raylib.h>

namespace Sprite
{
	struct Sprite
	{
		Texture2D texture;

		Rectangle source;

		Rectangle destination;

		Vector2 pivot;

		float rotation;

		Color tint;

	};

	void Init(Sprite& currentSprite, Texture2D texture, Rectangle source, Rectangle destination, Vector2 pivot, float rotation, Color tint);

	void Draw(Sprite currentSprite);
}

