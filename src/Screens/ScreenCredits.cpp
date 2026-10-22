#include "ScreenCredits.h"

#include <raylib.h>

#include "AudioManager.h"

#include "Utils/Sprite.h"
#include "Utils/Text.h"
#include "Objects/Button.h"

namespace Credits
{
	//Constantes
	const float BACK_TEXT_OFFSET_X = 65.0f;

	const float GAME_BY_TEXT_OFFSET_X = 12.0f;
	const float ART_BY_TEXT_OFFSET_X = 12.0f;
	const float MUSIC_BY_TEXT_OFFSET_X = 12.0f;
	const float FONT_BY_TEXT_OFFSET_X = 12.0f;

	const float CREDITS_FONT_SIZE = 40.0f;
	const float CREDITS_BUTTON_FONT_SIZE = 26.0f;
	const float CREDITS_TEXT_OFFSET_X = 650.0f;
	const float CREDITS_BUTTONS_TEXT_OFFSET_Y = 20.0f;

	const float BUTTONS_TEXT_OFFSET_Y = 5.0f;
	const float BUTTON_FONT_SIZE = 60.0f;
	const float BUTTON_FONT_SPACING = 2.0f;
	
	const float BACKGROUND_ALPHA_VALUE = 180.0f;

	const Vector2 INITIAL_BUTTON_POS = { 700.0f, 200.0f };
	const float BUTTON_OFFSET = 10.0f;

	//Background
	static Sprite::Sprite background;

	static Rectangle transparentBackground;
	static Color transparent;

	//Botones
	static Button::Button backButton;
	static Button::Button gameByButton;
	static Button::Button artByButton;
	static Button::Button musicByButton;
	static Button::Button fontByButton;

	//Font
	static Font menuFont;

	//Textos
	static Text::Text gameByText;
	static Text::Text artByText;
	static Text::Text musicByText;
	static Text::Text fontByText;


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

		Text::Init(text, menuFont, BUTTON_FONT_SIZE, "Back", textPos, BUTTON_FONT_SPACING, tint);

		//Hitbox backButton
		hitbox = destination;

		Button::Init(backButton, defaultColor, selectColor, hitbox, text, defaultSprite, selectSprite);

		buttonPos = INITIAL_BUTTON_POS;

		//GAME BY BUTTON

		//Default Sprite gameByButton
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

		//Select Sprite gameByButton
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

		//Text gameByButton
		textPos.x = destination.x + GAME_BY_TEXT_OFFSET_X;
		textPos.y = destination.y + CREDITS_BUTTONS_TEXT_OFFSET_Y;

		Text::Init(text, menuFont, CREDITS_BUTTON_FONT_SIZE, "Suarez Nahuel", textPos, BUTTON_FONT_SPACING, WHITE);

		//Hitbox gameByButton
		hitbox = destination;

		Button::Init(gameByButton, defaultColor, selectColor, hitbox, text, defaultSprite, selectSprite);

		//Text Game developed by:
		textPos.x = destination.x - CREDITS_TEXT_OFFSET_X;
		textPos.y = destination.y + BUTTONS_TEXT_OFFSET_Y;

		Text::Init(gameByText, menuFont, CREDITS_FONT_SIZE, "Game developed by:", textPos, BUTTON_FONT_SPACING, YELLOW);

		buttonPos.y += hitbox.height + BUTTON_OFFSET;


		//ART BY BUTTON

		//Default Sprite artByButton
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

		//Select Sprite artByButton
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

		//Text artByButton
		textPos.x = destination.x + GAME_BY_TEXT_OFFSET_X;
		textPos.y = destination.y + CREDITS_BUTTONS_TEXT_OFFSET_Y;

		Text::Init(text, menuFont, CREDITS_BUTTON_FONT_SIZE, "Arrastua Facundo", textPos, BUTTON_FONT_SPACING, WHITE);

		//Hitbox artByButton
		hitbox = destination;

		Button::Init(artByButton, defaultColor, selectColor, hitbox, text, defaultSprite, selectSprite);

		//Text Art by:
		textPos.x = destination.x - CREDITS_TEXT_OFFSET_X;
		textPos.y = destination.y + BUTTONS_TEXT_OFFSET_Y;

		Text::Init(artByText, menuFont, CREDITS_FONT_SIZE, "Art by:", textPos, BUTTON_FONT_SPACING, YELLOW);

		buttonPos.y += hitbox.height + BUTTON_OFFSET;


		//MUSIC BY BUTTON

		//Default Sprite musicByButton
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

		//Select Sprite musicByButton
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

		//Text musicByButton
		textPos.x = destination.x + GAME_BY_TEXT_OFFSET_X;
		textPos.y = destination.y + CREDITS_BUTTONS_TEXT_OFFSET_Y;

		Text::Init(text, menuFont, CREDITS_BUTTON_FONT_SIZE, "lowenergygirl", textPos, BUTTON_FONT_SPACING, WHITE);

		//Hitbox musicByButton
		hitbox = destination;

		Button::Init(musicByButton, defaultColor, selectColor, hitbox, text, defaultSprite, selectSprite);

		//Text Music by:
		textPos.x = destination.x - CREDITS_TEXT_OFFSET_X;
		textPos.y = destination.y + BUTTONS_TEXT_OFFSET_Y;

		Text::Init(musicByText, menuFont, CREDITS_FONT_SIZE, "Space Journey Music Pack by:", textPos, BUTTON_FONT_SPACING, YELLOW);

		buttonPos.y += hitbox.height + BUTTON_OFFSET;


		//FONT BY BUTTON

		//Default Sprite fontByButton
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

		//Select Sprite fontByButton
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

		//Text fontByButton
		textPos.x = destination.x + GAME_BY_TEXT_OFFSET_X;
		textPos.y = destination.y + CREDITS_BUTTONS_TEXT_OFFSET_Y;

		Text::Init(text, menuFont, CREDITS_BUTTON_FONT_SIZE, "Wojciech", textPos, BUTTON_FONT_SPACING, WHITE);

		//Hitbox fontByButton
		hitbox = destination;

		Button::Init(fontByButton, defaultColor, selectColor, hitbox, text, defaultSprite, selectSprite);

		//Text Font by:
		textPos.x = destination.x - CREDITS_TEXT_OFFSET_X;
		textPos.y = destination.y + BUTTONS_TEXT_OFFSET_Y;

		Text::Init(fontByText, menuFont, CREDITS_FONT_SIZE, "Font - Square Antiqua by: ", textPos, BUTTON_FONT_SPACING, YELLOW);
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

		//gameByButton
		Button::Update(gameByButton, mousePos);
		AudioManager::PlaySelectButtonSound(gameByButton);
		if (!gameByButton.isPressed && gameByButton.wasPressed)
		{
			gameByButton.isPressed = false;
			gameByButton.wasPressed = false;
			OpenURL("https://linktr.ee/Namitof");
		}

		//artByButton
		Button::Update(artByButton, mousePos);
		AudioManager::PlaySelectButtonSound(artByButton);
		if (!artByButton.isPressed && artByButton.wasPressed)
		{
			artByButton.isPressed = false;
			artByButton.wasPressed = false;
			OpenURL("https://linktr.ee/Blurklink");
		}

		//musicByButton
		Button::Update(musicByButton, mousePos);
		AudioManager::PlaySelectButtonSound(musicByButton);
		if (!musicByButton.isPressed && musicByButton.wasPressed)
		{
			musicByButton.isPressed = false;
			musicByButton.wasPressed = false;
			OpenURL("https://lowenergygirl.itch.io/space-journey");

		}

		//fontByButton
		Button::Update(fontByButton, mousePos);
		AudioManager::PlaySelectButtonSound(fontByButton);
		if (!fontByButton.isPressed && fontByButton.wasPressed)
		{
			fontByButton.isPressed = false;
			fontByButton.wasPressed = false;
			OpenURL("https://www.dafont.com/es/square-antiqua.font");
		}

	}

	void Draw()
	{

		Sprite::Draw(background);

		DrawRectangleRec(transparentBackground, transparent);

		Button::Draw(backButton);

		Button::Draw(gameByButton);
		Button::Draw(artByButton);
		Button::Draw(musicByButton);
		Button::Draw(fontByButton);

		Text::Draw(gameByText);
		Text::Draw(artByText);
		Text::Draw(musicByText);
		Text::Draw(fontByText);
	}
}