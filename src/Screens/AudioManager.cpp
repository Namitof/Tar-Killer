#include "AudioManager.h"

#include <raylib.h>

#include "Objects/Button.h"

namespace AudioManager
{
	//Sonidos
	static Sound select;

	//Musica
	static Music menu;
	static Music gameplay;

	void PlayMusic(Music currentMusic);


	void PlayMusic(Music currentMusic)
	{
		if (!IsMusicStreamPlaying(currentMusic))
		{
			PlayMusicStream(currentMusic);
		}
		UpdateMusicStream(currentMusic);
	}


	void Init(Sound selectSound, Music menuMusic, Music gameplayMusic)
	{
		select = selectSound;
		menu = menuMusic;
		gameplay = gameplayMusic;
	}

	void PlaySelectButtonSound(Button::Button& currentButton)
	{
		if (currentButton.isMouseOnButton)
		{
			if (!currentButton.soundIsPlaying)
			{
				currentButton.soundIsPlaying = true;
				PlaySound(select);
			}
		}
	}

	void PlayScreenMusic(ScreenMusic currentMusic)
	{
		switch (currentMusic)
		{
		case ScreenMusic::None:
			if (IsMusicStreamPlaying(menu))
			{
				StopMusicStream(menu);
			}
			if (IsMusicStreamPlaying(gameplay))
			{
				StopMusicStream(gameplay);
			}
			break;

		case ScreenMusic::Menu:
			if (IsMusicStreamPlaying(gameplay))
			{
				StopMusicStream(gameplay);
			}
			PlayMusic(menu);
			break;

		case ScreenMusic::Gameplay:
			if (IsMusicStreamPlaying(menu))
			{
				StopMusicStream(menu);
			}
			PlayMusic(gameplay);
			break;

		default:
			break;
		}
	}

	void PauseScreenMusic(ScreenMusic currentMusic)
	{
		switch (currentMusic)
		{
		case ScreenMusic::Menu:
			if (IsMusicStreamPlaying(menu))
			{
				PauseMusicStream(menu);
			}
			break;

		case ScreenMusic::Gameplay:
			if (IsMusicStreamPlaying(gameplay))
			{
				PauseMusicStream(gameplay);
			}
			break;

		default:
			break;
		}
	}

	void ResumeScreenMusic(ScreenMusic currentMusic)
	{
		switch (currentMusic)
		{
		case ScreenMusic::Menu:
			if (!IsMusicStreamPlaying(menu))
			{
				ResumeMusicStream(menu);
			}
			break;

		case ScreenMusic::Gameplay:
			if (!IsMusicStreamPlaying(gameplay))
			{
				ResumeMusicStream(gameplay);
			}
			break;

		default:
			break;
		}
	}
}