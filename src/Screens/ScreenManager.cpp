#include "ScreenManager.h"

#include "ScreenGame.h"

#include <raylib.h>

#include <cstdlib>
#include <ctime>

namespace ScreenManager
{
	
	void Init(ScreenOptions& currentScreen);

	void Update(ScreenOptions& currentScreen, float deltaTime);

	void Draw(ScreenOptions& currentScreen);


	void Init(ScreenOptions& currentScreen)
	{
		InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tar Killer");

		currentScreen = ScreenOptions::Play;

		Game::Init();

	}

	void Update(ScreenOptions& currentScreen, float deltaTime)
	{
		switch (currentScreen)
		{
		case ScreenManager::ScreenOptions::Menu:
			break;
		case ScreenManager::ScreenOptions::Play:
			Game::Update(deltaTime);
			break;
		case ScreenManager::ScreenOptions::Settings:
			break;
		case ScreenManager::ScreenOptions::Rules:
			break;
		case ScreenManager::ScreenOptions::Credits:
			break;
		case ScreenManager::ScreenOptions::Exit:
			break;
		case ScreenManager::ScreenOptions::Pause:
			break;
		case ScreenManager::ScreenOptions::EndGame:
			break;
		default:
			break;
		}
	}

	void Draw(ScreenOptions& currentScreen)
	{
		BeginDrawing();
		ClearBackground(WHITE);

		switch (currentScreen)
		{
		case ScreenManager::ScreenOptions::Menu:
			break;
		case ScreenManager::ScreenOptions::Play:
			Game::Draw();
			break;
		case ScreenManager::ScreenOptions::Settings:
			break;
		case ScreenManager::ScreenOptions::Rules:
			break;
		case ScreenManager::ScreenOptions::Credits:
			break;
		case ScreenManager::ScreenOptions::Exit:
			break;
		case ScreenManager::ScreenOptions::Pause:
			break;
		case ScreenManager::ScreenOptions::EndGame:
			break;
		default:
			break;
		}

		EndDrawing();
	}

	void Run()
	{
		srand(time(NULL));

		ScreenOptions currentScreen = ScreenOptions::None;
		float deltaTime = 0.0f;

		//Inicialización
		Init(currentScreen);

		//Loop
		while (!WindowShouldClose())
		{
			deltaTime = GetFrameTime();

			//Update (actualizacion)
			Update(currentScreen, deltaTime);

			//Draw (dibujado)
			Draw(currentScreen);
		}

		//Cierre
		CloseWindow();
	}
}