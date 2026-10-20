#pragma once

#include <raylib.h>

#include "../Utils/Sprite.h"

namespace Player
{
    const float PLAYER_RADIUS = 50.0f;

    const float PLAYER_MAX_SPEED = 300.0f;

    const int PLAYER_LIFES = 3;

	struct Player
	{
        Vector2 pos;

        Vector2 direction;

        float radius;

        //Speed
        Vector2 speed;

        float maxSpeed;

        //Se mueve el pivote al punto de origen del rectangulo
        Rectangle spriteRectangle;
        Vector2 pivot;
        
        float rotation;

        //Estadisticas de juego
        int score;
        int lifes;

        //Sprite
        Sprite::Sprite sprite;
	};

    void Init(Player& player, Sprite::Sprite playerSprite, int screenWidth, int screenHeight);

    void Move(Player& player, float deltaTime);

    void CalculateNewAngle(Player& player, Vector2 posMouse);

    void Update(Player& player, float deltaTime);

    void Draw(Player player);
}