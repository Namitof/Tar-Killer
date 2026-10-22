#include "ScreenManager.h"

#include <raylib.h>

#include <cstdlib>
#include <ctime>

#include "ScreenGame.h"
#include "ScreenMenu.h"
#include "ScreenSettings.h"
#include "ScreenRules.h"
#include "ScreenCredits.h"
#include "ScreenPause.h"
#include "ScreenEndGame.h"

namespace ScreenManager
{
	//Constantes
	const int FONT_SIZE = 100;

	//Recursos del juego
	static Texture2D menuBackground;
	static Texture2D gameBackground;
	static Texture2D optionsBackground;

	static Texture2D logo;

	static Texture2D player;

	static Texture2D defaultButton;
	static Texture2D selectButton;

	static Font font;

	static Sound selectSound;



	//Declaracion de funciones

	void Init(ScreenOptions& currentScreen);

	void Update(ScreenOptions& currentScreen, float deltaTime, bool& gameIsRunning);

	void Draw(ScreenOptions& currentScreen);

	void Delete();


	//Definicion de funciones

	void Init(ScreenOptions& currentScreen)
	{
		InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tar Killer");

		currentScreen = ScreenOptions::Menu;

		//Carga de recursos y distribucion
		menuBackground = LoadTexture("res/background/BackgroundMenu.png");
		gameBackground = LoadTexture("res/background/BackgroundGame.png");
		optionsBackground = LoadTexture("res/background/BackgroundOptions.png");

		logo = LoadTexture("res/logo/LogoTarKiller.png");

		player = LoadTexture("res/player/player.png");

		font = LoadFontEx("res/font/SquareAntiqua-Bold.ttf", FONT_SIZE, NULL, 0);

		defaultButton = LoadTexture("res/buttons/DefaultButton.png");
		selectButton = LoadTexture("res/buttons/SelectButton.png");

		selectSound = LoadSound("res/sounds/select.wav");

		//Init a cada escena del juego
		Menu::Init(menuBackground, logo, font, defaultButton, selectButton, SCREEN_WIDTH, SCREEN_HEIGHT, selectSound);

		Game::Init(gameBackground, SCREEN_WIDTH, SCREEN_HEIGHT, player, font, defaultButton, selectButton, selectSound);

		Settings::Init(optionsBackground, font, defaultButton, selectButton, SCREEN_WIDTH, SCREEN_HEIGHT, selectSound);

		Rules::Init(optionsBackground, font, defaultButton, selectButton, SCREEN_WIDTH, SCREEN_HEIGHT, selectSound);

		Credits::Init(optionsBackground, font, defaultButton, selectButton, SCREEN_WIDTH, SCREEN_HEIGHT, selectSound);

		Pause::Init(font, defaultButton, selectButton, SCREEN_WIDTH, SCREEN_HEIGHT, selectSound);

		EndGame::Init(font, defaultButton, selectButton, SCREEN_WIDTH, SCREEN_HEIGHT, selectSound);

	}

	void Update(ScreenOptions& currentScreen, float deltaTime, bool& gameIsRunning)
	{
		bool playButtonPressed;
		bool settingsButtonPressed;
		bool rulesButtonPressed;
		bool creditsButtonPressed;
		bool exitButtonPressed;
		bool backButtonPresed;
		bool pauseButtonPresed;
		bool isGameOver;

		switch (currentScreen)
		{
		case ScreenManager::ScreenOptions::Menu:
			Menu::Update(playButtonPressed, settingsButtonPressed, rulesButtonPressed, creditsButtonPressed, exitButtonPressed);

			if (playButtonPressed)
			{
				currentScreen = ScreenOptions::Play;
				Game::Init(gameBackground, SCREEN_WIDTH, SCREEN_HEIGHT, player, font, defaultButton, selectButton, selectSound);
			}
			else if (settingsButtonPressed)
			{
				currentScreen = ScreenOptions::Settings;
			}
			else if (rulesButtonPressed)
			{
				currentScreen = ScreenOptions::Rules;
			}
			else if (creditsButtonPressed)
			{
				currentScreen = ScreenOptions::Credits;
			}
			else if (exitButtonPressed)
			{
				currentScreen = ScreenOptions::Exit;
			}

			break;
		case ScreenManager::ScreenOptions::Play:
			Game::Update(pauseButtonPresed, isGameOver, deltaTime, SCREEN_WIDTH, SCREEN_HEIGHT);

			if (pauseButtonPresed)
			{
				currentScreen = ScreenOptions::Pause;
			
			}
			
			if (isGameOver)
			{
				currentScreen = ScreenOptions::EndGame;
			}

			break;
		case ScreenManager::ScreenOptions::Settings:
			Settings::Update(backButtonPresed);

			if (backButtonPresed)
			{
				currentScreen = ScreenOptions::Menu;
			}

			break;
		case ScreenManager::ScreenOptions::Rules:
			Rules::Update(backButtonPresed);

			if (backButtonPresed)
			{
				currentScreen = ScreenOptions::Menu;
			}

			break;
		case ScreenManager::ScreenOptions::Credits:
			Credits::Update(backButtonPresed);

			if (backButtonPresed)
			{
				currentScreen = ScreenOptions::Menu;
			}

			break;
		case ScreenManager::ScreenOptions::Exit:
			gameIsRunning = false;
			break;
		case ScreenManager::ScreenOptions::Pause:
			Pause::Update(exitButtonPressed, backButtonPresed);

			if (exitButtonPressed)
			{
				currentScreen = ScreenOptions::Menu;
				Game::Init(gameBackground, SCREEN_WIDTH, SCREEN_HEIGHT, player, font, defaultButton, selectButton, selectSound);
			}
			else if (backButtonPresed)
			{
				currentScreen = ScreenOptions::Play;
			}

			break;
		case ScreenManager::ScreenOptions::EndGame:
			EndGame::Update(exitButtonPressed, playButtonPressed);

			if (playButtonPressed)
			{
				currentScreen = ScreenOptions::Play;
				Game::Init(gameBackground, SCREEN_WIDTH, SCREEN_HEIGHT, player, font, defaultButton, selectButton, selectSound);
			}
			else if (exitButtonPressed)
			{
				currentScreen = ScreenOptions::Menu;
				Game::Init(gameBackground, SCREEN_WIDTH, SCREEN_HEIGHT, player, font, defaultButton, selectButton, selectSound);
			}

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
			Menu::Draw();
			break;
		case ScreenManager::ScreenOptions::Play:
			Game::Draw();
			break;
		case ScreenManager::ScreenOptions::Settings:
			Settings::Draw();
			break;
		case ScreenManager::ScreenOptions::Rules:
			Rules::Draw();
			break;
		case ScreenManager::ScreenOptions::Credits:
			Credits::Draw();
			break;
		case ScreenManager::ScreenOptions::Exit:
			break;
		case ScreenManager::ScreenOptions::Pause:
			Game::Draw();
			Pause::Draw();
			break;
		case ScreenManager::ScreenOptions::EndGame:
			Game::Draw();
			EndGame::Draw();
			break;
		default:
			break;
		}

		EndDrawing();
	}

	void Delete()
	{
		//Unload a todos los recursos
		UnloadTexture(menuBackground);
		UnloadTexture(gameBackground);
		UnloadTexture(optionsBackground);

		UnloadTexture(logo);

		UnloadTexture(player);

		UnloadFont(font);

		UnloadTexture(defaultButton);
		UnloadTexture(selectButton);

		UnloadSound(selectSound);

	}

	void Run()
	{
		SetRandomSeed(static_cast<unsigned int>(time(NULL)));

		ScreenOptions currentScreen = ScreenOptions::None;
		float deltaTime = 0.0f;

		bool gameIsRuning = true;

		InitAudioDevice();

		//Inicialización
		Init(currentScreen);

		//Loop
		while (!WindowShouldClose() && gameIsRuning)
		{
			deltaTime = GetFrameTime();

			//Update (actualizacion)
			Update(currentScreen, deltaTime, gameIsRuning);

			//Draw (dibujado)
			Draw(currentScreen);
		}

		Delete();

		CloseAudioDevice();

		//Cierre
		CloseWindow();
	}
}