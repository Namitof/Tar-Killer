#include "ScreenMenu.h"

#include <raylib.h>

#include "../Utils/Sprite.h"
#include "../Utils/Text.h"

#include "../Objects/Button.h"


namespace Menu
{
	//Background
	static Sprite::Sprite background;

	//Botones
	static Button::Button playButton;
	static Button::Button settingsButton;
	static Button::Button rulesButton;
	static Button::Button creditsButton;
	static Button::Button exitButton;

	//Logo
	static Sprite::Sprite logo;

	//Font
	static Font menuFont;


	void BackgroundInit(Texture2D menuBackground, int screenWidth, int screenHeight);

	void LogoInit(Texture2D logoTexture);

	void ButtonsInit(Texture2D defaultButtonTexture, Texture2D selectButtonTexture);


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

	void LogoInit(Texture2D logoTexture)
	{
		//Componentes del struct sprite
		Rectangle source;
		Rectangle destination;
		Vector2 pivot;
		float rotation;
		Color tint;

		//Init a logo
		source.x = 0.0f;
		source.y = 0.0f;
		source.width = static_cast<float>(logoTexture.width);
		source.height = static_cast<float>(logoTexture.height);

		destination.x = LOGO_POS_X;
		destination.y = LOGO_POS_Y;
		destination.width = static_cast<float>(logoTexture.width);
		destination.height = static_cast<float>(logoTexture.height);

		pivot.x = 0.0f;
		pivot.y = 0.0f;

		rotation = 0;

		tint = WHITE;

		Sprite::Init(logo, logoTexture, source, destination, pivot, rotation, tint);
	}

	void ButtonsInit(Texture2D defaultButtonTexture, Texture2D selectButtonTexture)
	{
		//Componentes del struct sprite
		Rectangle source;
		Rectangle destination;
		Vector2 pivot;
		float rotation;
		Color tint;

		//Init a cada boton
		Vector2 buttonPos = INITIAL_BUTTON_POS;

		Color currentColor = WHITE;
		Color defaultColor = WHITE;
		Color selectColor = WHITE;

		Sprite::Sprite defaultSprite;
		Sprite::Sprite selectSprite;

		Text::Text text;

		Rectangle hitbox;

		// PLAYBUTTON
		//Default Sprite playButton
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

		//Select Sprite playButton
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

		//Text playButton
		text.font = menuFont;
		text.fontSize = 60; //**********
		text.text = "Play";
		text.position.x = destination.x + 65; //**********
		text.position.y = destination.y + 5; //**********
		text.spacing = 2; //**********
		text.tint = WHITE;//**********

		//Hitbox playButton
		hitbox = destination;

		Button::Init(playButton, defaultColor, selectColor, hitbox, text, defaultSprite, selectSprite);

		buttonPos.y += hitbox.height + BUTTON_OFFSET;

		// SETTINGSBUTTON
		//Default Sprite settingsButton
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

		//Select Sprite settingsButton
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

		//Text settingsButton
		text.font = menuFont;
		text.fontSize = 60;//**********
		text.text = "Settings";
		text.position.x = destination.x + 65;//**********
		text.position.y = destination.y + 5;//**********
		text.spacing = 2;//**********
		text.tint = WHITE;

		//Hitbox settingsButton
		hitbox = destination;

		Button::Init(settingsButton, defaultColor, selectColor, hitbox, text, defaultSprite, selectSprite);

		buttonPos.y += hitbox.height + BUTTON_OFFSET;

		// RULESBUTTON
		//Default Sprite rulesButton
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

		//Select Sprite rulesButton
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

		//Text rulesButton
		text.font = menuFont;
		text.fontSize = 60;//**********
		text.text = "Rules";
		text.position.x = destination.x + 65;//**********
		text.position.y = destination.y + 5;//**********
		text.spacing = 2;//**********
		text.tint = WHITE;

		//Hitbox rulesButton
		hitbox = destination;

		Button::Init(rulesButton, defaultColor, selectColor, hitbox, text, defaultSprite, selectSprite);

		buttonPos.y += hitbox.height + BUTTON_OFFSET;

		// CREDITSBUTTON
		//Default Sprite creditsButton
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

		//Select Sprite creditsButton
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

		//Text creditsButton
		text.font = menuFont;
		text.fontSize = 60;//**********
		text.text = "Credits";
		text.position.x = destination.x + 65;//**********
		text.position.y = destination.y + 5;//**********
		text.spacing = 2;//**********
		text.tint = WHITE;

		//Hitbox creditsButton
		hitbox = destination;

		Button::Init(creditsButton, defaultColor, selectColor, hitbox, text, defaultSprite, selectSprite);

		buttonPos.y += hitbox.height + BUTTON_OFFSET;

		// EXITBUTTON
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
		text.font = menuFont;
		text.fontSize = 60;//**********
		text.text = "Exit";
		text.position.x = destination.x + 65;//**********
		text.position.y = destination.y + 5;//**********
		text.spacing = 2;//**********
		text.tint = WHITE;

		//Hitbox creditsButton
		hitbox = destination;

		Button::Init(exitButton, defaultColor, selectColor, hitbox, text, defaultSprite, selectSprite);
	}

	void Init(Texture2D menuBackground, Texture2D logoTexture, Font font, Texture2D defaultButtonTexture, Texture2D selectButtonTexture, int screenWidth, int screenHeight)
	{
		BackgroundInit(menuBackground, screenWidth, screenHeight);

		LogoInit(logoTexture);

		//font
		menuFont = font;

		ButtonsInit(defaultButtonTexture, selectButtonTexture);
	}

	void Update(bool& playButtonPressed, bool& settingsButtonPressed, bool& rulesButtonPressed, bool& creditsButtonPressed, bool& exitButtonPressed)
	{
		//Actualizar estado de botones
		Vector2 mousePos = GetMousePosition();

		//Play
		Button::Update(playButton, mousePos);
		if (playButton.isMouseOnButton && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			playButtonPressed = true;
		}
		else
		{
			playButtonPressed = false;
		}

		//Settings
		Button::Update(settingsButton, mousePos);
		if (settingsButton.isMouseOnButton && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			settingsButtonPressed = true;
		}
		else
		{
			settingsButtonPressed = false;
		}

		//Rules
		Button::Update(rulesButton, mousePos);
		if (rulesButton.isMouseOnButton && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			rulesButtonPressed = true;
		}
		else
		{
			rulesButtonPressed = false;
		}

		//Credits
		Button::Update(creditsButton, mousePos);
		if (creditsButton.isMouseOnButton && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			creditsButtonPressed = true;
		}
		else
		{
			creditsButtonPressed = false;
		}

		//Exit
		Button::Update(exitButton, mousePos);
		if (exitButton.isMouseOnButton && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			exitButtonPressed = true;
		}
		else
		{
			exitButtonPressed = false;
		}
	}

	void Draw()
	{
		Sprite::Draw(background);
		Sprite::Draw(logo);
		Button::Draw(playButton);
		Button::Draw(settingsButton);
		Button::Draw(rulesButton);
		Button::Draw(creditsButton);
		Button::Draw(exitButton);
	}
}