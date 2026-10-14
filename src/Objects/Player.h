#pragma once

#include <raylib.h>


namespace Player
{
    const float PLAYER_RADIUS = 50.0f;
    const float PLAYER_SPEED = 100.0f;

    const float PLAYER_MIN_SPEED = 50.0f;
    const float PLAYER_MAX_SPEED = 300.0f;

    const float PLAYER_MIN_DISTANCE = 1.0f;
    const float PLAYER_MAX_DISTANCE = 500.0f;

	struct Player
	{
        Vector2 pos;
        Vector2 direction;
        float radius;
        float speed;
	};

    void Init(Player& player);

    void Update(Player& player, float deltaTime);

    void Draw(Player player);

    void Move(Player& player, float deltaTime);
}