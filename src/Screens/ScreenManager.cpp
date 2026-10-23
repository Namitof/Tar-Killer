#include "ScreenManager.h"

#include <cstdlib>
#include <ctime>

#include <raylib.h>

#include "ScreenGame.h"
#include "ScreenMenu.h"
#include "ScreenSettings.h"
#include "ScreenRules.h"
#include "ScreenCredits.h"
#include "ScreenPause.h"
#include "ScreenEndGame.h"
#include "AudioManager.h"
#include "Objects/Enemy.h"
#include "Objects/Bullet.h"

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

	static Texture2D enemyLarge;
	static Texture2D enemyMedium;
	static Texture2D enemySmall;

	static Texture2D bullet;

	static Texture2D defaultButton;
	static Texture2D selectButton;

	static Font font;

	static Sound selectSound;
	static Sound shootSound;
	static Sound enemyHitSound;
	static Sound gameOverSound;
	static Sound teleportSound;
	static Sound playerHitSound;
	static Sound playerMoveSound;

	static Music menuMusic;
	static Music gameMusic;

	static int playerMaxScore;
	static int playerCurrentScore;

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

		playerMaxScore = -1;
		playerCurrentScore = -1;

		//Carga de recursos y distribucion
		menuBackground = LoadTexture("res/background/BackgroundMenu.png");
		gameBackground = LoadTexture("res/background/BackgroundGame.png");
		optionsBackground = LoadTexture("res/background/BackgroundOptions.png");

		logo = LoadTexture("res/logo/LogoTarKiller.png");

		player = LoadTexture("res/player/player.png");

		enemyLarge = LoadTexture("res/enemy/LargeEnemy.png");
		enemyMedium = LoadTexture("res/enemy/MediumEnemy.png");
		enemySmall = LoadTexture("res/enemy/SmallEnemy.png");

		bullet = LoadTexture("res/bullet/bullet.png");

		font = LoadFontEx("res/font/SquareAntiqua-Bold.ttf", FONT_SIZE, NULL, 0);

		defaultButton = LoadTexture("res/buttons/DefaultButton.png");
		selectButton = LoadTexture("res/buttons/SelectButton.png");

		selectSound = LoadSound("res/sounds/select.wav");
		shootSound = LoadSound("res/sounds/shoot.wav");
		enemyHitSound = LoadSound("res/sounds/hit.wav");
		gameOverSound = LoadSound("res/sounds/gameover.wav");
		teleportSound = LoadSound("res/sounds/teleport.wav");
		playerHitSound = LoadSound("res/sounds/damaged.wav");
		playerMoveSound = LoadSound("res/sounds/move.wav");

		menuMusic = LoadMusicStream("res/musics/menu.wav");
		gameMusic = LoadMusicStream("res/musics/gameplay.wav");

		Enemy::SetAllSprites(enemyLarge, enemyMedium, enemySmall);
		Bullet::SetSprite(bullet);

		AudioManager::Init(selectSound, shootSound, enemyHitSound, gameOverSound, teleportSound, playerHitSound, playerMoveSound, menuMusic, gameMusic);

		//Init a cada escena del juego
		Menu::Init(menuBackground, logo, font, defaultButton, selectButton, SCREEN_WIDTH, SCREEN_HEIGHT);

		Game::Init(gameBackground, SCREEN_WIDTH, SCREEN_HEIGHT, player, font, defaultButton, selectButton);

		Settings::Init(optionsBackground, font, defaultButton, selectButton, SCREEN_WIDTH, SCREEN_HEIGHT);

		Rules::Init(optionsBackground, font, defaultButton, selectButton, SCREEN_WIDTH, SCREEN_HEIGHT);

		Credits::Init(optionsBackground, font, defaultButton, selectButton, SCREEN_WIDTH, SCREEN_HEIGHT);

		Pause::Init(font, defaultButton, selectButton, SCREEN_WIDTH, SCREEN_HEIGHT);

		EndGame::Init(font, defaultButton, selectButton, SCREEN_WIDTH, SCREEN_HEIGHT);
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
			AudioManager::PlayScreenMusic(AudioManager::ScreenMusic::Menu);
			Menu::Update(playButtonPressed, settingsButtonPressed, rulesButtonPressed, creditsButtonPressed, exitButtonPressed, playerMaxScore);

			if (playButtonPressed)
			{
				currentScreen = ScreenOptions::Play;
				Game::Init(gameBackground, SCREEN_WIDTH, SCREEN_HEIGHT, player, font, defaultButton, selectButton);
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
			AudioManager::PlayScreenMusic(AudioManager::ScreenMusic::Gameplay);
			Game::Update(pauseButtonPresed, isGameOver, deltaTime, SCREEN_WIDTH, SCREEN_HEIGHT, playerCurrentScore);

			if (pauseButtonPresed)
			{
				currentScreen = ScreenOptions::Pause;
			
			}
			
			if (isGameOver)
			{
				AudioManager::PlayGameOverSound();
				currentScreen = ScreenOptions::EndGame;
			}

			if (playerCurrentScore > playerMaxScore)
			{
				playerMaxScore = playerCurrentScore;
			}

			break;
		case ScreenManager::ScreenOptions::Settings:
			AudioManager::PlayScreenMusic(AudioManager::ScreenMusic::Menu);
			Settings::Update(backButtonPresed);

			if (backButtonPresed)
			{
				currentScreen = ScreenOptions::Menu;
			}

			break;
		case ScreenManager::ScreenOptions::Rules:
			AudioManager::PlayScreenMusic(AudioManager::ScreenMusic::Menu);
			Rules::Update(backButtonPresed);

			if (backButtonPresed)
			{
				currentScreen = ScreenOptions::Menu;
			}

			break;
		case ScreenManager::ScreenOptions::Credits:
			AudioManager::PlayScreenMusic(AudioManager::ScreenMusic::Menu);
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
			//AudioManager::PlayScreenMusic(AudioManager::ScreenMusic::Gameplay);
			AudioManager::PauseScreenMusic(AudioManager::ScreenMusic::Gameplay);
			Pause::Update(exitButtonPressed, backButtonPresed);

			if (exitButtonPressed)
			{
				currentScreen = ScreenOptions::Menu;
				Game::Init(gameBackground, SCREEN_WIDTH, SCREEN_HEIGHT, player, font, defaultButton, selectButton);
				AudioManager::ResumeScreenMusic(AudioManager::ScreenMusic::Gameplay);

			}
			else if (backButtonPresed)
			{
				currentScreen = ScreenOptions::Play;
				AudioManager::ResumeScreenMusic(AudioManager::ScreenMusic::Gameplay);

			}

			break;
		case ScreenManager::ScreenOptions::EndGame:
			AudioManager::PlayScreenMusic(AudioManager::ScreenMusic::None);
			EndGame::Update(exitButtonPressed, playButtonPressed, playerCurrentScore);

			if (playButtonPressed)
			{
				currentScreen = ScreenOptions::Play;
				Game::Init(gameBackground, SCREEN_WIDTH, SCREEN_HEIGHT, player, font, defaultButton, selectButton);
			}
			else if (exitButtonPressed)
			{
				currentScreen = ScreenOptions::Menu;
				Game::Init(gameBackground, SCREEN_WIDTH, SCREEN_HEIGHT, player, font, defaultButton, selectButton);
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

		UnloadTexture(enemyLarge);
		UnloadTexture(enemyMedium);
		UnloadTexture(enemySmall);

		UnloadTexture(bullet);

		UnloadFont(font);

		UnloadTexture(defaultButton);
		UnloadTexture(selectButton);

		UnloadSound(selectSound);
		UnloadSound(shootSound);
		UnloadSound(enemyHitSound);
		UnloadSound(gameOverSound);
		UnloadSound(teleportSound);
		UnloadSound(playerHitSound);
		UnloadSound(playerMoveSound);

		UnloadMusicStream(menuMusic);
		UnloadMusicStream(gameMusic);

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