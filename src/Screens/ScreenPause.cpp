#include "ScreenRules.h"

#include <raylib.h>

#include "Utils/Sprite.h"
#include "Utils/Text.h"

#include "Objects/Button.h"

namespace Pause
{
	//Constantes
	const float EXIT_TEXT_OFFSET_X = 70.0f;
	const float CONTINUE_TEXT_OFFSET_X = 8.0f;
	const float BUTTONS_TEXT_OFFSET_Y = 5.0f;
	const float BUTTON_FONT_SIZE = 60.0f;
	const float BUTTON_FONT_SPACING = 2.0f;
	const float BUTTON_SPAWN_OFFSET = 100.0f;

	const float TITLE_TEXT_SIZE = 100.0f;

	//Background
	static Rectangle transparentBackground;
	static Color transparent;

	//Botones
	static Button::Button continueButton;
	static Button::Button exitButton;

	//Textos
	static Text::Text pauseText;

	//Font
	static Font pauseFont;


	void TransparentBackgroundInit(int screenWidth, int screenHeight);

	void ButtonsInit(Texture2D defaultButtonTexture, Texture2D selectButtonTexture, int screenWidth, int screenHeight);

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

		//EXIT
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
		textPos.x = destination.x + EXIT_TEXT_OFFSET_X;
		textPos.y = destination.y + BUTTONS_TEXT_OFFSET_Y;

		Text::Init(text, pauseFont, BUTTON_FONT_SIZE, "Exit", textPos, BUTTON_FONT_SPACING, WHITE);

		//Hitbox playButton
		hitbox = destination;

		Button::Init(exitButton, defaultColor, selectColor, hitbox, text, defaultSprite, selectSprite);


		//CONTINUE
		//Default Sprite backButton
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

		//Select Sprite backButton
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

		//Text backButton
		textPos.x = destination.x + CONTINUE_TEXT_OFFSET_X;
		textPos.y = destination.y + BUTTONS_TEXT_OFFSET_Y;

		Text::Init(text, pauseFont, BUTTON_FONT_SIZE, "Continue", textPos, BUTTON_FONT_SPACING, WHITE);

		//Hitbox playButton
		hitbox = destination;

		Button::Init(continueButton, defaultColor, selectColor, hitbox, text, defaultSprite, selectSprite);
	}

	void TextInit(int screenWidth, int screenHeight)
	{
		Vector2 textPos;

		textPos.x = static_cast<float>((screenWidth / 13 ) * 5);
		textPos.y = static_cast<float>((screenHeight / 10) * 3);

		Text::Init(pauseText, pauseFont, TITLE_TEXT_SIZE, "Pause", textPos, BUTTON_FONT_SPACING, WHITE);
	}

	void Init(Font font, Texture2D defaultButtonTexture, Texture2D selectButtonTexture, int screenWidth, int screenHeight)
	{
		TransparentBackgroundInit(screenWidth, screenHeight);

		//font
		pauseFont = font;

		ButtonsInit(defaultButtonTexture, selectButtonTexture, screenWidth, screenHeight);

		TextInit(screenWidth, screenHeight);
	}

	void Update(bool& exitButtonPressed, bool& continueButtonPressed)
	{
		//Actualizar estado de botones
		Vector2 mousePos = GetMousePosition();

		//Exit
		Button::Update(exitButton, mousePos);
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

		//Continue
		Button::Update(continueButton, mousePos);
		if (!continueButton.isPressed && continueButton.wasPressed)
		{
			continueButton.isPressed = false;
			continueButton.wasPressed = false;
			continueButtonPressed = true;
		}
		else
		{
			continueButtonPressed = false;
		}
	}

	void Draw()
	{

		DrawRectangleRec(transparentBackground, transparent);

		Text::Draw(pauseText);

		Button::Draw(continueButton);

		Button::Draw(exitButton);
	}
}