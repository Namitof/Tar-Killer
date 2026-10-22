#include "ScreenRules.h"

#include <raylib.h>

#include "AudioManager.h"

#include "Utils/Sprite.h"
#include "Utils/Text.h"
#include "Objects/Button.h"

namespace Rules
{
	//Constantes
	const float BACK_TEXT_OFFSET_X = 65.0f;
	const float BUTTONS_TEXT_OFFSET_Y = 5.0f;
	const float BUTTON_FONT_SIZE = 60.0f;
	const float BUTTON_FONT_SPACING = 2.0f;

	const float BACKGROUND_ALPHA_VALUE = 180.0f;

	const float TITLE_FONT_SIZE = 50.0f;
	const float CONTENT_FONT_SIZE = 40.0f;

	//Background
	static Sprite::Sprite background;

	static Rectangle transparentBackground;
	static Color transparent;

	//Botones
	static Button::Button backButton;

	//Font
	static Font rulesFont;

	static Text::Text objetiveTextTitle;
	static Text::Text objetiveTextContent;

	static Text::Text enemiesTextTitle;
	static Text::Text enemiesTextContent1;
	static Text::Text enemiesTextContent2;
	static Text::Text enemiesTextContent3;

	static Text::Text wavesTextTitle;
	static Text::Text wavesTextContent;

	void BackgroundInit(Texture2D menuBackground, int screenWidth, int screenHeight);

	void TransparentBackgroundInit(int screenWidth, int screenHeight);

	void ButtonsInit(Texture2D defaultButtonTexture, Texture2D selectButtonTexture, int screenWidth, int screenHeight);

	void TextInit(int screenHeight);

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
		transparent.a = static_cast<unsigned char>(BACKGROUND_ALPHA_VALUE);
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

		Text::Init(text, rulesFont, BUTTON_FONT_SIZE, "Back", textPos, BUTTON_FONT_SPACING, WHITE);

		//Hitbox playButton
		hitbox = destination;

		Button::Init(backButton, defaultColor, selectColor, hitbox, text, defaultSprite, selectSprite);
	}

	void TextInit(int screenHeight)
	{
		const int POS_X = 20;
		const int OFFSET_POS_Y = 60;
		
		Vector2 textPos;

		//OBJECTIVE TITLE
		textPos.x = POS_X;
		textPos.y = static_cast<float>((screenHeight / 12) * 2);

		Text::Init(objetiveTextTitle, rulesFont, TITLE_FONT_SIZE, "OBJECTIVE", textPos, BUTTON_FONT_SPACING, WHITE);

		//OBJECTIVE CONTENT
		textPos.x = POS_X;
		textPos.y += OFFSET_POS_Y;

		Text::Init(objetiveTextContent, rulesFont, CONTENT_FONT_SIZE, "Destroy the Tar Plague and beat your high score!", textPos, BUTTON_FONT_SPACING, WHITE);



		//ENEMIES TITLE
		textPos.x = POS_X;
		textPos.y += OFFSET_POS_Y;

		Text::Init(enemiesTextTitle, rulesFont, TITLE_FONT_SIZE, "ENEMIES", textPos, BUTTON_FONT_SPACING, WHITE);

		//ENEMIES CONTENT 1
		textPos.x = POS_X;
		textPos.y += OFFSET_POS_Y;

		Text::Init(enemiesTextContent1, rulesFont, CONTENT_FONT_SIZE, " - Purple: Splits into two Medium Tars when destroyed.", textPos, BUTTON_FONT_SPACING, WHITE);

		//ENEMIES CONTENT 2
		textPos.x = POS_X;
		textPos.y += OFFSET_POS_Y;

		Text::Init(enemiesTextContent2, rulesFont, CONTENT_FONT_SIZE, " - Green: Splits into two Small Tars when destroyed.", textPos, BUTTON_FONT_SPACING, WHITE);

		//ENEMIES CONTENT 3
		textPos.x = POS_X;
		textPos.y += OFFSET_POS_Y;

		Text::Init(enemiesTextContent3, rulesFont, CONTENT_FONT_SIZE, " - Yellow: Disappears when destroyed.", textPos, BUTTON_FONT_SPACING, WHITE);


		//WAVES TITLE
		textPos.x = POS_X;
		textPos.y += OFFSET_POS_Y;

		Text::Init(wavesTextTitle, rulesFont, TITLE_FONT_SIZE, "WAVES", textPos, BUTTON_FONT_SPACING, WHITE);

		//WAVES CONTENT
		textPos.x = POS_X;
		textPos.y += OFFSET_POS_Y;

		Text::Init(wavesTextContent, rulesFont, CONTENT_FONT_SIZE, "Destroy larger Tars to trigger bigger waves!", textPos, BUTTON_FONT_SPACING, WHITE);
	}

	void Init(Texture2D menuBackground, Font font, Texture2D defaultButtonTexture, Texture2D selectButtonTexture, int screenWidth, int screenHeight)
	{
		BackgroundInit(menuBackground, screenWidth, screenHeight);

		TransparentBackgroundInit(screenWidth, screenHeight);

		//font
		rulesFont = font;
		
		TextInit(screenHeight);

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

		Text::Draw(objetiveTextTitle);
		Text::Draw(objetiveTextContent);
		Text::Draw(enemiesTextTitle);
		Text::Draw(enemiesTextContent1);
		Text::Draw(enemiesTextContent2);
		Text::Draw(enemiesTextContent3);
		Text::Draw(wavesTextTitle);
		Text::Draw(wavesTextContent);

		Button::Draw(backButton);
	}
}