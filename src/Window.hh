#pragma once

#include "Debug.hh"
#include "Vector2.hh"

#include <SDL2/SDL.h>

#include <string>

class Window
{
public:
	Window(const std::string& title);
	~Window();

	bool valid() { return window; }

	// set new window size and return old size
	Vec2i swapSize(Vec2i newSize);
	
	SDL_Window* window;
private:
	Vec2i size;
	SDL_GLContext ctx;
};


