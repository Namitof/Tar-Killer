#pragma once


namespace ScreenManager
{
	const int SCREEN_WIDTH = 1024;
	const int SCREEN_HEIGHT = 768;

	enum class ScreenOptions
	{
		None = 0,
		Menu,
		Play,
		Settings,
		Rules,
		Credits,
		Exit,
		Pause,
		EndGame
	};

	void Run();
}
