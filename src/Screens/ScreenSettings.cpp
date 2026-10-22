#include "ScreenSettings.h"

#include <raylib.h>

#include "AudioManager.h"

#include "Utils/Sprite.h"
#include "Utils/Text.h"
#include "Objects/Button.h"

namespace Settings
{
	//Constantes
	const float BACK_TEXT_OFFSET_X = 65.0f;
	const float BUTTONS_TEXT_OFFSET_Y = 5.0f;
	const float BUTTON_FONT_SIZE = 60.0f;
	const float BUTTON_FONT_SPACING = 2.0f;

	//Background
	static Sprite::Sprite background;

	static Rectangle transparentBackground;
	static Color transparent;

	//Botones
	static Button::Button backButton;
	//Agregar botones de sonido

	//Nave
	//static Sprite::Sprite logo;

	//Font
	static Font menuFont;


	void BackgroundInit(Texture2D menuBackground, int screenWidth, int screenHeight);

	void TransparentBackgroundInit(int screenWidth, int screenHeight);

	void ButtonsInit(Texture2D defaultButtonTexture, Texture2D selectButtonTexture, int screenWidth, int screenHeight);

	void BackgroundInit(Texture2D menuBackground, int screenWidth, int screenHeight)
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
		source.width = static_cast<float>(menuBackground.width);
		source.height = static_cast<float>(menuBackground.height);

		destination.x = 0.0f;
		destination.y = 0.0f;
		destination.width = static_cast<float>(screenWidth);
		destination.height = static_cast<float>(screenHeight);

		pivot.x = 0.0f;
		pivot.y = 0.0f;

		rotation = 0;

		tint = WHITE;

		Sprite::Init(background, menuBackground, source, destination, pivot, rotation, tint);
	}

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

	void ButtonsInit(Texture2D defaultButtonTexture, Texture2D selectButtonTexture, int screenWidth, int screenHeight)
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

		//Default Sprite backButton
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

		//Select Sprite backButton
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

		//Text backButton
		textPos.x = destination.x + BACK_TEXT_OFFSET_X;
		textPos.y = destination.y + BUTTONS_TEXT_OFFSET_Y;

		Text::Init(text, menuFont, BUTTON_FONT_SIZE, "Back", textPos, BUTTON_FONT_SPACING, WHITE);

		//Hitbox playButton
		hitbox = destination;

		Button::Init(backButton, defaultColor, selectColor, hitbox, text, defaultSprite, selectSprite);
	}

	void Init(Texture2D menuBackground, Font font, Texture2D defaultButtonTexture, Texture2D selectButtonTexture, int screenWidth, int screenHeight)
	{
		BackgroundInit(menuBackground, screenWidth, screenHeight);

		TransparentBackgroundInit(screenWidth, screenHeight);

		//font
		menuFont = font;

		ButtonsInit(defaultButtonTexture, selectButtonTexture, screenWidth, screenHeight);
	}

	void Update(bool& backButtonPressed)
	{
		//Actualizar estado de botones
		Vector2 mousePos = GetMousePosition();

		//Back
		Button::Update(backButton, mousePos);
		AudioManager::PlaySelectButtonSound(backButton);
		if (!backButton.isPressed && backButton.wasPressed)
		{
			backButton.isPressed = false;
			backButton.wasPressed = false;
			backButtonPressed = true;
		}
		else
		{
			backButtonPressed = false;
		}

	}

	void Draw()
	{

		Sprite::Draw(background);

		DrawRectangleRec(transparentBackground, transparent);

		Button::Draw(backButton);
	}
}