/*
Suarez Nahuel
12/10/2026
Juego Tar Killer
*/

#include "raylib.h"
#include "raymath.h"
#include "Screens/ScreenManager.h"

int main()
{
    ScreenManager::Run();

    /*const float screenWidth = 800;
    const float screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Nueva Ventana");

    Rectangle shape;
    shape.x = screenWidth / 2;
    shape.y = screenHeight / 2;
    shape.width = 50;
    shape.height = 300;

    Vector2 pivot;
    pivot.x = shape.width / 2;
    pivot.y = shape.height / 2;

    float rotation = 0.0f;
    float rotationSpeed = 100.0f;

    while (!WindowShouldClose())
    {
        rotation += rotationSpeed * GetFrameTime();

        BeginDrawing();
        ClearBackground(WHITE);

        DrawRectanglePro(shape, pivot, rotation, RED);

        EndDrawing();
    }

    CloseWindow();*/

    /*const float screenWidth = 800;
    const float screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Nueva Ventana");

    Vector2 pos;
    pos.x = screenWidth / 2;
    pos.y = screenHeight / 2;

    Vector2 direction;

    float radius = 50.0f;
    float speed = 100.0f;

    while (!WindowShouldClose())
    {
        direction = Vector2Subtract(GetMousePosition(), pos);

        direction.x = GetMouseX() - pos.x;
        direction.y = GetMouseY() - pos.y;

        Vector2 dirNormalizado = Vector2Normalize(direction);

        pos.x += dirNormalizado.x * GetFrameTime() * speed;
        pos.y += dirNormalizado.y * GetFrameTime() * speed;

        BeginDrawing();
        ClearBackground(WHITE);

        DrawCircle(pos.x, pos.y, radius, RED);

        EndDrawing();
    }

    CloseWindow();*/

    return 0;
}