#pragma once

#include <raylib.h>

#include "Objects/Button.h"

namespace AudioManager
{
	enum class ScreenMusic
	{
		None = 0,
		Menu,
		Gameplay
	};

	void Init(Sound selectSound, Sound shootSound, Music menuMusic, Music gameplayMusic);

	void PlaySelectButtonSound(Button::Button& currentButton);

	void PlayShootSound();

	void PlayScreenMusic(ScreenMusic currentMusic);

	void PauseScreenMusic(ScreenMusic currentMusic);

	void ResumeScreenMusic(ScreenMusic currentMusic);
}