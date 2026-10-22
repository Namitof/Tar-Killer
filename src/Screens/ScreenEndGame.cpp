#include "ScreenRules.h"

#include <raylib.h>

#include "Utils/Sprite.h"
#include "Utils/Text.h"

#include "Objects/Button.h"

namespace EndGame
{
	//Constantes
	const float EXIT_TEXT_OFFSET_X = 80.0f;
	const float RETRY_TEXT_OFFSET_X = 55.0f;
	const float EXIT_TEXT_OFFSET_Y = 5.0f;
	const float RETRY_TEXT_OFFSET_Y = 1.0f;
	const float BUTTON_FONT_SIZE = 60.0f;
	const float BUTTON_FONT_SPACING = 2.0f;
	const float BUTTON_SPAWN_OFFSET = 100.0f;

	const float TITLE_TEXT_SIZE = 100.0f;
	const float SCORE_TEXT_SIZE = 80.0f;

	//Background
	static Rectangle transparentBackground;
	static Color transparent;

	//Botones
	static Button::Button retryButton;
	static Button::Button exitButton;

	//Textos
	static Text::Text endText;
	static Text::Text scoreText;

	//Font
	static Font endFont;


	void TransparentBackgroundInit(int screenWidth, int screenHeight);

	void ButtonsInit(Texture2D defaultButtonTexture, Texture2D selectButtonTexture, int screenWidth, int screenHeight, Sound selectSound);

	void TextInit(int screenWidth, int screenHeight);


	void TransparentBackgroundInit(int screenWidth, int screenHeight)
	{
		//Init a transparentBackground
		transparent.a = static_cast<unsigned char>(100.0f);
		transparent.b = static_cast<unsigned char>(0.0f);
		transparent.g = static_cast<unsigned char>(0.0f);
		transparent.r = static_cast<unsigned char>(0.0f);

		transparentBackground.x = 0.0f;
		transparentBackground.y = 0.0f;
		transparentBackground.width = static_cast<float>(screenWidth);
		transparentBackground.height = static_cast<float>(screenHeight);
	}

	void ButtonsInit(Texture2D defaultButtonTexture, Texture2D selectButtonTexture, int screenWidth, int screenHeight, Sound selectSound)
	{
		//Componentes del struct sprite
		Rectangle source;
		Rectangle destination;
		Vector2 pivot;
		float rotation;
		Color tint;

		//Init a cada boton
		Vector2 buttonPos;
		buttonPos.x = static_cast<float>((screenWidth / 2) - (Button::BUTTON_WIDTH / 2));
		buttonPos.y = static_cast<float>((screenHeight / 12) * 10);

		Vector2 textPos;

		Color currentColor = WHITE;
		Color defaultColor = WHITE;
		Color selectColor = WHITE;

		Sprite::Sprite defaultSprite;
		Sprite::Sprite selectSprite;

		Text::Text text;

		Rectangle hitbox;

		//EXIT
		//Default Sprite exitButton
		source.x = 0.0f;
		source.y = 0.0f;
		source.width = static_cast<float>(defaultButtonTexture.width);
		source.height = static_cast<float>(defaultButtonTexture.height);

		destination.x = buttonPos.x;
		destination.y = buttonPos.y;
		destination.width = Button::BUTTON_WIDTH;
		destination.height = Button::BUTTON_HEIGHT;

		pivot.x = 0.0f;
		pivot.y = 0.0f;

		rotation = 0;

		tint = WHITE;

		Sprite::Init(defaultSprite, defaultButtonTexture, source, destination, pivot, rotation, tint);

		//Select Sprite exitButton
		source.x = 0.0f;
		source.y = 0.0f;
		source.width = static_cast<float>(selectButtonTexture.width);
		source.height = static_cast<float>(selectButtonTexture.height);

		destination.x = buttonPos.x;
		destination.y = buttonPos.y;
		destination.width = Button::BUTTON_WIDTH;
		destination.height = Button::BUTTON_HEIGHT;

		pivot.x = 0.0f;
		pivot.y = 0.0f;

		rotation = 0;

		tint = WHITE;

		Sprite::Init(selectSprite, selectButtonTexture, source, destination, pivot, rotation, tint);

		//Text exitButton
		textPos.x = destination.x + EXIT_TEXT_OFFSET_X;
		textPos.y = destination.y + EXIT_TEXT_OFFSET_Y;

		Text::Init(text, endFont, BUTTON_FONT_SIZE, "Exit", textPos, BUTTON_FONT_SPACING, WHITE);

		//Hitbox exitButton
		hitbox = destination;

		Button::Init(exitButton, defaultColor, selectColor, hitbox, text, defaultSprite, selectSprite, selectSound);


		//RETRY
		//Default Sprite retryButton
		source.x = 0.0f;
		source.y = 0.0f;
		source.width = static_cast<float>(defaultButtonTexture.width);
		source.height = static_cast<float>(defaultButtonTexture.height);

		destination.x = buttonPos.x;
		destination.y = buttonPos.y - BUTTON_SPAWN_OFFSET;
		destination.width = Button::BUTTON_WIDTH;
		destination.height = Button::BUTTON_HEIGHT;

		pivot.x = 0.0f;
		pivot.y = 0.0f;

		rotation = 0;

		tint = WHITE;

		Sprite::Init(defaultSprite, defaultButtonTexture, source, destination, pivot, rotation, tint);

		//Select Sprite retryButton
		source.x = 0.0f;
		source.y = 0.0f;
		source.width = static_cast<float>(selectButtonTexture.width);
		source.height = static_cast<float>(selectButtonTexture.height);

		destination.x = buttonPos.x;
		destination.y = buttonPos.y - BUTTON_SPAWN_OFFSET;
		destination.width = Button::BUTTON_WIDTH;
		destination.height = Button::BUTTON_HEIGHT;

		pivot.x = 0.0f;
		pivot.y = 0.0f;

		rotation = 0;

		tint = WHITE;

		Sprite::Init(selectSprite, selectButtonTexture, source, destination, pivot, rotation, tint);

		//Text retryButton
		textPos.x = destination.x + RETRY_TEXT_OFFSET_X;
		textPos.y = destination.y + RETRY_TEXT_OFFSET_Y;

		Text::Init(text, endFont, BUTTON_FONT_SIZE, "Retry", textPos, BUTTON_FONT_SPACING, WHITE);

		//Hitbox retryButton
		hitbox = destination;

		Button::Init(retryButton, defaultColor, selectColor, hitbox, text, defaultSprite, selectSprite, selectSound);
	}

	void TextInit(int screenWidth, int screenHeight)
	{
		Vector2 textPos;

		textPos.x = static_cast<float>((screenWidth / 13) * 5);
		textPos.y = static_cast<float>((screenHeight / 10) * 3);

		Text::Init(endText, endFont, TITLE_TEXT_SIZE, "GAME OVER", textPos, BUTTON_FONT_SPACING, RED);

		textPos.x = static_cast<float>((screenWidth / 13) * 5);
		textPos.y = static_cast<float>((screenHeight / 10) * 4);

		Text::Init(scoreText, endFont, TITLE_TEXT_SIZE, "Score: 0", textPos, BUTTON_FONT_SPACING, WHITE);
	}

	void Init(Font font, Texture2D defaultButtonTexture, Texture2D selectButtonTexture, int screenWidth, int screenHeight, Sound selectSound)
	{
		TransparentBackgroundInit(screenWidth, screenHeight);

		//font
		endFont = font;

		ButtonsInit(defaultButtonTexture, selectButtonTexture, screenWidth, screenHeight, selectSound);

		TextInit(screenWidth, screenHeight);
	}

	void Update(bool& exitButtonPressed, bool& retryButtonPressed)
	{
		//Actualizar estado de botones
		Vector2 mousePos = GetMousePosition();

		//Exit
		Button::Update(exitButton, mousePos);
		Button::PlaySound(exitButton);
		if (!exitButton.isPressed && exitButton.wasPressed)
		{
			exitButton.isPressed = false;
			exitButton.wasPressed = false;
			exitButtonPressed = true;
		}
		else
		{
			exitButtonPressed = false;
		}

		//Retry
		Button::Update(retryButton, mousePos);
		Button::PlaySound(retryButton);
		if (!retryButton.isPressed && retryButton.wasPressed)
		{
			retryButton.isPressed = false;
			retryButton.wasPressed = false;
			retryButtonPressed = true;
		}
		else
		{
			retryButtonPressed = false;
		}

		scoreText.text = "Score: " + std::to_string(10);

	}

	void Draw()
	{

		DrawRectangleRec(transparentBackground, transparent);

		Text::Draw(endText);

		Text::Draw(scoreText);

		Button::Draw(retryButton);

		Button::Draw(exitButton);
	}
}