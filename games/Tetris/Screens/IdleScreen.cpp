#include "IdleScreen.h"

#include "../TetrisGame.h"
#include "../TetrisScreens.h"

#include <assets/Bitmaps.h>

void IdleScreen::enter()
{
	clearScreen();
	drawText(2, 1, (char*)"TETRIS", Color::BLACK, Orientation::DEG_0, 1);
	drawObject(3, 12, StatsQrCode, true);
}

void IdleScreen::update()
{
	if (isAnyKeyPressed())
	{
		setNextScreen(getScreens().SelectLevel);
		return;
	}
}
