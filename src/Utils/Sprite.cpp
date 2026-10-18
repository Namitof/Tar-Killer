#include "Sprite.h"

#include <raylib.h>

namespace Sprite
{
	void Init(Sprite& currentSprite, Texture2D texture, Rectangle source, Rectangle destination, Vector2 pivot, float rotation, Color tint)
	{
		currentSprite.texture = texture;
		currentSprite.source = source;
		currentSprite.destination = destination;
		currentSprite.pivot = pivot;
		currentSprite.rotation = rotation;
		currentSprite.tint = tint;
	}

	void Draw(Sprite currentSprite)
	{
		DrawTexturePro(currentSprite.texture, currentSprite.source, currentSprite.destination, currentSprite.pivot, currentSprite.rotation, currentSprite.tint);
	}
}

