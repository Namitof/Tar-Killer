#include "ScreenGame.h"

#include <raylib.h>

#include <string>

#include "Objects/Player.h"
#include "Objects/Bullet.h"
#include "Objects/ColisionManager.h"
#include "Objects/Button.h"
#include "Objects/Enemy.h"
#include "Utils/Sprite.h"
#include "Utils/Text.h"

namespace Game
{
	//Constantes
	const float PAUSE_TEXT_OFFSET_X = 12.0f;
	const float PAUSE_TEXT_OFFSET_Y = 8.0f;
	const float BUTTON_FONT_SIZE = 35.0f;
	const float BUTTON_FONT_SPACING = 2.0f;

	const float PAUSE_BUTTON_WIDTH = 120.0f;
	const float PAUSE_BUTTON_HEIGHT = 60.0f;

	const float HUD_FONT_SIZE = 40.0f;

	const int INITIAL_ENEMY_QUANTITY = 2;

	static Sprite::Sprite background;

	static Font gameFont;

	static Text::Text score;

	static Text::Text lives;

	static Button::Button pauseButton;

	static Player::Player player;

	static Bullet::Bullet bulletPool[Bullet::MAX_BULLETS];

	static int enemyCountEliminated; //Cantidad de enemigos eliminados
	static int currentEnemyQuantity; //Cantidad de enemigos actuales
	static bool allEnemiesDestroyed;
	static Enemy::Enemy enemyPool[Enemy::MAX_ENEMYS];


	void BackgroundInit(Texture2D gameBackground, int screenWidth, int screenHeight);

	void PlayerInit(Texture2D playerTexture, int screenWidth, int screenHeight);

	void HudInit(Texture2D defaultButtonTexture, Texture2D selectButtonTexture, int screenWidth);

	Vector2 GenerateRandomDirection();

	Vector2 GenerateRandomPosition();
	

	void BackgroundInit(Texture2D gameBackground, int screenWidth, int screenHeight)
	{
		//Componentes del struct sprite
		Rectangle source;
		Rectangle destination;
		Vector2 pivot;
		float rotation;
		Color tint;

		//Init a background
		source.x = 0.0f;
		source.y = 0.0f;
		source.width = static_cast<float>(gameBackground.width);
		source.height = static_cast<float>(gameBackground.height);

		destination.x = 0.0f;
		destination.y = 0.0f;
		destination.width = static_cast<float>(screenWidth);
		destination.height = static_cast<float>(screenHeight);

		pivot.x = 0.0f;
		pivot.y = 0.0f;

		rotation = 0;

		tint = WHITE;

		Sprite::Init(background, gameBackground, source, destination, pivot, rotation, tint);
	}

	void PlayerInit(Texture2D playerTexture, int screenWidth, int screenHeight)
	{
		Sprite::Sprite playerSprite;

		//Componentes del struct sprite
		Rectangle source;
		Rectangle destination;
		Vector2 pivot;
		float rotation;
		Color tint;

		//Init a background
		source.x = 0.0f;
		source.y = 0.0f;
		source.width = static_cast<float>(playerTexture.width);
		source.height = static_cast<float>(playerTexture.height);

		destination.x = 0.0f;
		destination.y = 0.0f;
		destination.width = static_cast<float>(Player::PLAYER_RADIUS * 2);
		destination.height = static_cast<float>(Player::PLAYER_RADIUS * 2);

		pivot.x = 0.0f;
		pivot.y = 0.0f;

		rotation = 0;

		tint = WHITE;

		Sprite::Init(playerSprite, playerTexture, source, destination, pivot, rotation, tint);

		Player::Init(player, playerSprite, screenWidth, screenHeight);
	}

	void HudInit(Texture2D defaultButtonTexture, Texture2D selectButtonTexture, int screenWidth)
	{
		//Componentes del struct sprite
		Rectangle source;
		Rectangle destination;
		Vector2 pivot;
		float rotation;
		Color tint;

		//Init a cada boton
		Vector2 buttonPos;

		Vector2 textPos;

		Color currentColor = WHITE;
		Color defaultColor = WHITE;
		Color selectColor = WHITE;

		Sprite::Sprite defaultSprite;
		Sprite::Sprite selectSprite;

		Text::Text text;

		Rectangle hitbox;

		// PAUSEBUTTON
		//Default Sprite pauseButton
		source.x = 0.0f;
		source.y = 0.0f;
		source.width = static_cast<float>(defaultButtonTexture.width);
		source.height = static_cast<float>(defaultButtonTexture.height);

		destination.width = PAUSE_BUTTON_WIDTH;
		destination.height = PAUSE_BUTTON_HEIGHT;

		buttonPos.x = screenWidth - destination.width - BUTTON_OFFSET;
		buttonPos.y = BUTTON_OFFSET;

		destination.x = buttonPos.x;
		destination.y = buttonPos.y;

		pivot.x = 0.0f;
		pivot.y = 0.0f;

		rotation = 0;

		tint = WHITE;

		Sprite::Init(defaultSprite, defaultButtonTexture, source, destination, pivot, rotation, tint);

		//Select Sprite pauseButton
		source.x = 0.0f;
		source.y = 0.0f;
		source.width = static_cast<float>(selectButtonTexture.width);
		source.height = static_cast<float>(selectButtonTexture.height);

		destination.width = PAUSE_BUTTON_WIDTH;
		destination.height = PAUSE_BUTTON_HEIGHT;

		buttonPos.x = screenWidth - destination.width - BUTTON_OFFSET;
		buttonPos.y = BUTTON_OFFSET;

		destination.x = buttonPos.x;
		destination.y = buttonPos.y;

		pivot.x = 0.0f;
		pivot.y = 0.0f;

		rotation = 0;

		tint = WHITE;

		Sprite::Init(selectSprite, selectButtonTexture, source, destination, pivot, rotation, tint);

		//Text pauseButton
		textPos.x = destination.x + PAUSE_TEXT_OFFSET_X;
		textPos.y = destination.y + PAUSE_TEXT_OFFSET_Y;

		Text::Init(text, gameFont, BUTTON_FONT_SIZE, "Pause", textPos, BUTTON_FONT_SPACING, WHITE);

		//Hitbox pauseButton
		hitbox = destination;

		Button::Init(pauseButton, defaultColor, selectColor, hitbox, text, defaultSprite, selectSprite);

		//Lives
		textPos.x = PAUSE_TEXT_OFFSET_X;
		textPos.y = PAUSE_TEXT_OFFSET_X;

		Text::Init(lives, gameFont, HUD_FONT_SIZE, "Lives: 0", textPos, BUTTON_FONT_SPACING, WHITE);

		//Score
		textPos.x = PAUSE_TEXT_OFFSET_X;
		textPos.y = PAUSE_TEXT_OFFSET_X + HUD_FONT_SIZE;

		Text::Init(score, gameFont, HUD_FONT_SIZE, "Score: 0", textPos, BUTTON_FONT_SPACING, WHITE);

	}

	Vector2 GenerateRandomDirection()
	{
		Vector2 direction;

		//Constantes
		const int MAX_ANGLE = 36000;
		const int MIN_ANGLE = 0;
		const float DIVISION = 100.0f;

		int randomNumber = GetRandomValue(MIN_ANGLE, MAX_ANGLE);

		float angle = randomNumber / DIVISION;

		angle *= DEG2RAD;

		float x = static_cast<float>(cos(angle)); 
		float y = static_cast<float>(sin(angle));

		direction.x = x;
		direction.y = y;

		return direction;
	}

	Vector2 GenerateRandomPosition()
	{
		Vector2 position;

		//Constantes
		const int MIN_POS = 0;
		const int MAX_POS = 768;

		//const Vector2 MIN_POS = {-50.0f, 0.0f};
		//const Vector2 MAX_POS = {-50.0f, 768.0f};
		//const float DIVISION = 100.0f;

		int randomNumber = GetRandomValue(MIN_POS, MAX_POS);

		position.x = -50.0f;
		position.y = static_cast<float>(randomNumber);

		return position;
	}

	void Init(Texture2D gameBackground, int screenWidth, int screenHeight, Texture2D playerTexture, Font font, Texture2D defaultButtonTexture, Texture2D selectButtonTexture)
	{
		BackgroundInit(gameBackground, screenWidth, screenHeight);

		PlayerInit(playerTexture, screenWidth, screenHeight);

		gameFont = font;

		HudInit(defaultButtonTexture, selectButtonTexture, screenWidth);

		for (int i = 0; i < Bullet::MAX_BULLETS; i++)
		{
			Bullet::Init(bulletPool[i]);
		}

		enemyCountEliminated = 0;
		currentEnemyQuantity = 0;
		allEnemiesDestroyed = false;
		for (int i = 0; i < Enemy::MAX_ENEMYS; i++)
		{
			Enemy::Init(enemyPool[i], Enemy::EnemySize::Large);
		}

	}

	void Update(bool& pauseButtonPressed, float deltaTime, int width, int height)
	{
		//HUD

		//Textos
		lives.text = "Lives: " + std::to_string(player.lifes);
		score.text = "Score: " + std::to_string(player.score);

		//Boton
		//Actualizar estado de botones
		Vector2 mousePos = GetMousePosition();

		//Pause
		Button::Update(pauseButton, mousePos);
		if (!pauseButton.isPressed && pauseButton.wasPressed)
		{
			pauseButton.isPressed = false;
			pauseButton.wasPressed = false;
			pauseButtonPressed = true;
		}
		else
		{
			pauseButtonPressed = false;
		}

		// PARTIDA
		Player::Update(player, deltaTime);

		// Disparo
		if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
		{
			for (int i = 0; i < Bullet::MAX_BULLETS; i++)
			{
				if (!bulletPool[i].isActive)
				{
					Bullet::Init(bulletPool[i]);
					bulletPool[i].isActive = true;
					Bullet::SetPos(bulletPool[i], player.pos);
					Bullet::SetDirection(bulletPool[i], player.direction);
					break;
				}
			}
		}

		// Actualizacion de las balas
		for (int i = 0; i < Bullet::MAX_BULLETS; i++)
		{
			Bullet::Update(bulletPool[i], deltaTime);
		}

		// Actualizacion de los enemigos
		for (int i = 0; i < Enemy::MAX_ENEMYS; i++)
		{
			if (enemyPool[i].isActive)
			{
				Enemy::Update(enemyPool[i], deltaTime);
			}
		}

		if (enemyCountEliminated == currentEnemyQuantity)
		{
			allEnemiesDestroyed = true;

			enemyCountEliminated = 0;

			if (currentEnemyQuantity < Enemy::MAX_LARGE_ENEMY)
			{
				currentEnemyQuantity += INITIAL_ENEMY_QUANTITY;
			}
			else
			{
				currentEnemyQuantity = Enemy::MAX_LARGE_ENEMY;
			}
		}

		if (allEnemiesDestroyed)
		{
			int count = 0;

			while (count < currentEnemyQuantity)
			{
				for (int i = 0; i < Enemy::MAX_ENEMYS; i++)
				{
					if (!enemyPool[i].isActive)
					{
						if (count == currentEnemyQuantity)
							break;

						Enemy::Init(enemyPool[i], Enemy::EnemySize::Large);

						enemyPool[i].isActive = true;

						//Generar direccion random
						Enemy::SetDireccion(enemyPool[i], GenerateRandomDirection());

						//Generar posicion random
						Enemy::SetPos(enemyPool[i], GenerateRandomPosition());

						count++;
					}
				}
			}

			allEnemiesDestroyed = false;
		}

		ColisionManager::CheckColisions(player, bulletPool, enemyPool, width, height, enemyCountEliminated);

		if (player.lifes <= 0)
		{
			pauseButtonPressed = true;
		}
	}

	void Draw()
	{
		//Background
		Sprite::Draw(background);

		//Enemys
		for (int i = 0; i < Enemy::MAX_ENEMYS; i++)
		{
			if (enemyPool[i].isActive)
			{
				Enemy::Draw(enemyPool[i]);
			}
		}

		//Bullets
		for (int i = 0; i < Bullet::MAX_BULLETS; i++)
		{
			if (bulletPool[i].isActive)
			{
				Bullet::Draw(bulletPool[i]);
			}
		}

		//Player
		Player::Draw(player);

		//HUD
		Button::Draw(pauseButton);
		Text::Draw(lives);
		Text::Draw(score);

	}
}

//Centrar nave en el centro

//Pausa y HUD