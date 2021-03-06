#include "SDLPlatform.h"
#include <iostream>
#include <Framebuffer.h>

SDLPlatform::SDLPlatform()
{
}

void SDLPlatform::init()
{
	SDL_Init(SDL_INIT_VIDEO);
	_window = SDL_CreateWindow("Flipdot", 100, 100, 1000, 800, SDL_WINDOW_SHOWN);
	_driver = new SDLFlipdotDriver(*this, _window, 2, 2);
	_framebuffer = new Framebuffer(*_driver);
}

void SDLPlatform::done()
{
	SDL_DestroyWindow( _window );
	SDL_Quit();
}

void SDLPlatform::update()
{
	SDL_Event e;
	while( SDL_PollEvent( &e ) != 0 )
	{
		handleSDLEvent(e);
	}

	_gamepad.update(getTicks());
	SDL_Delay(2);
}

void SDLPlatform::handleSDLEvent(SDL_Event& event)
{
	switch (event.type)
	{
		case SDL_KEYDOWN:
		case SDL_KEYUP:
			handleKeyEvent(event.key);
			break;

		case SDL_QUIT:
			_doQuit = true;
			break;

	}
}

Framebuffer& SDLPlatform::getFramebuffer()
{
	return *_framebuffer;
}

uint32_t SDLPlatform::getTicks()
{
	return SDL_GetTicks();
}

bool SDLPlatform::doQuit()
{
	return _doQuit;
}

Gamepad& SDLPlatform::getGamepad()
{
	return _gamepad;
}

void SDLPlatform::handleKeyEvent(SDL_KeyboardEvent &key)
{
	GamepadKey* padkey = nullptr;

	switch (key.keysym.sym)
	{
		case SDLK_LEFT:
			padkey = &_gamepad.West;
			break;
		case SDLK_RIGHT:
			padkey = &_gamepad.East;
			break;
		case SDLK_UP:
			padkey = &_gamepad.North;
			break;
		case SDLK_DOWN:
			padkey = &_gamepad.South;
			break;
		case SDLK_SPACE:
			padkey = &_gamepad.Select;
			break;
		case SDLK_RETURN:
			padkey = &_gamepad.Start;
			break;
		case SDLK_a:
			padkey = &_gamepad.A;
			break;
		case SDLK_s:
		case SDLK_b:
			padkey = &_gamepad.B;
			break;
		default:
			return;
	}

	if (key.type == SDL_KEYDOWN)
	{
		padkey->update(getTicks(), true);
	} else if (key.type == SDL_KEYUP) {
		padkey->update(getTicks(), false);
	}

}
