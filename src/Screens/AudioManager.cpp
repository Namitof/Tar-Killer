#include "AudioManager.h"

#include <raylib.h>

#include "Objects/Button.h"

namespace AudioManager
{
	//Sonidos
	static Sound select;
	static Sound shoot;
	static Sound enemyHit;
	static Sound gameOver;
	static Sound teleport;
	static Sound playerHit;
	static Sound move;

	//Musica
	static Music menu;
	static Music gameplay;

	static float masterVolume;

	void PlayMusic(Music currentMusic);


	void PlayMusic(Music currentMusic)
	{
		if (!IsMusicStreamPlaying(currentMusic))
		{
			PlayMusicStream(currentMusic);
		}
		UpdateMusicStream(currentMusic);
	}


	void Init(Sound selectSound, Sound shootSound, Sound enemyHitSound, Sound gameOverSound, Sound teleportSound, Sound playerHitSound, Sound moveSound, Music menuMusic, Music gameplayMusic)
	{
		select = selectSound;
		shoot = shootSound;
		enemyHit = enemyHitSound;
		gameOver = gameOverSound;
		teleport = teleportSound;
		playerHit = playerHitSound;
		move = moveSound;

		menu = menuMusic;
		gameplay = gameplayMusic;

		masterVolume = 1.0f;
		SetMasterVolume(masterVolume);
	}

	void ReduceVolume()
	{
		masterVolume -= 0.1f;
		if (masterVolume <= 0.0f)
		{
			masterVolume = 0.0f;
		}
		SetMasterVolume(masterVolume);

	}

	void IncreaseVolume()
	{
		masterVolume += 0.1f;
		if (masterVolume >= 1.0f)
		{
			masterVolume = 1.0f;
		}
		SetMasterVolume(masterVolume);
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

	void PlayShootSound()
	{
		if (!IsSoundPlaying(shoot))
		{
			PlaySound(shoot);
		}
	}

	void PlayEnemyHitSound()
	{
		if (!IsSoundPlaying(enemyHit))
		{
			PlaySound(enemyHit);
		}
	}

	void PlayGameOverSound()
	{
		if (!IsSoundPlaying(gameOver))
		{
			PlaySound(gameOver);
		}
	}

	void PlayTeleportSound()
	{
		if (!IsSoundPlaying(teleport))
		{
			PlaySound(teleport);
		}
	}

	void PlayPlayerHitSound()
	{
		if (!IsSoundPlaying(playerHit))
		{
			PlaySound(playerHit);
		}
	}

	void PlayPlayerMoveSound()
	{
		if (!IsSoundPlaying(move))
		{
			PlaySound(move);
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