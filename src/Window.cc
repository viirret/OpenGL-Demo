#include "Window.hh"

#include <GL/glew.h>
#include <iostream>

Window::Window(const std::string& title)
{
    // Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0) 
	{
        std::cerr << "Error: Could not initialize SDL: " << SDL_GetError() << std::endl;
		return;
    }

	// get monitor size
	SDL_DisplayMode display;
	if(SDL_GetCurrentDisplayMode(0, &display))
	{
		std::cerr << "Couldn't get display info: " << SDL_GetError() << std::endl;
		return;
	}

	DBG_LOG("Display size w: %d h: %d", display.w, display.h);

    // Create the window
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, display.w, display.h, SDL_WINDOW_OPENGL);
    if(!window) 
	{
        std::cerr << "Error: Could not create window: " << SDL_GetError() << std::endl;
		return;
    }

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	// create ctx
	ctx = SDL_GL_CreateContext(window);

	// start glew
	glewInit();

	// update window size
	SDL_GetWindowSize(window, &size.x, &size.y);	
	DBG_LOG("window created\n");
}

Window::~Window()
{
	if(window) 
		SDL_DestroyWindow(window);

	SDL_Quit();
}

Vec2i Window::swapSize(Vec2i newSize)
{
	Vec2i oldSize = size;
	size = newSize;
	return oldSize;
}
