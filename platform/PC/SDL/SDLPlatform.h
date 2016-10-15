#pragma once

#include <IPlatform.h>
#include <VirtualGamepad.h>

#include <SDL2/SDL.h>
#include "SDLFlipdotDriver.h"

class SDLPlatform : IPlatform
{
	public:
		SDLPlatform();

		void init() override;
		void done() override;
		void update() override;

		Framebuffer &getFramebuffer() override;
		IGamepad &getGamepad() override;

		uint32_t getTicks() override;
		bool doQuit() override;

	private:
		SDLFlipdotDriver *_driver = nullptr;
		Framebuffer *_framebuffer = nullptr;
		SDL_Window *_window = nullptr;
		VirtualGamepad _gamepad;
		bool _doQuit = false;

		void handleSDLEvent(SDL_Event &event);
		void handleKeyEvent(SDL_KeyboardEvent &key);
};

