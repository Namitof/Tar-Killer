#include "ScreenRules.h"

#include <raylib.h>

#include "../Utils/Sprite.h"
#include "../Utils/Text.h"

#include "../Objects/Button.h"

namespace Rules
{
	//Background
	static Sprite::Sprite background;

	static Rectangle transparentBackground;
	static Color transparent;

	//Botones
	static Button::Button backButton;

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
		text.font = menuFont;
		text.fontSize = 60; //**********
		text.text = "Back";
		text.position.x = destination.x + 65; //**********
		text.position.y = destination.y + 5; //**********
		text.spacing = 2; //**********
		text.tint = WHITE;//**********

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
		if (backButton.isMouseOnButton && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
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