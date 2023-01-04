#include "Program.hh"

#include <GL/glew.h>
#include <SDL2/SDL.h>

Program::Program() : 
	running(true), window(""),
	camera(),
	scene(camera),
	cameraPosition(glm::vec3(0.0f))
{
	// give a nice background
	glClearColor(0.0f, 0.0f, 0.4f, 1.0f);
	
	// enable depth testing
	glEnable(GL_DEPTH_TEST);

	// update program
	while(running)
		update();
}

void Program::update()
{
	updateTime();
	render();
	trackEvents();
	updateCamera();
}

void Program::updateCamera()
{
	if(isMoving)
		camera.translate(cameraPosition, cameraFrontVector);
}

void Program::updateTime()
{
	currentTime = SDL_GetTicks();
	elapsedTime = currentTime - lastTime;
	lastTime = currentTime;

	// sleep for the remaining FPS
	int elapsedTimeMs = SDL_GetTicks() - currentTime;
	if(elapsedTimeMs < FPS)
		SDL_Delay(FPS - elapsedTimeMs);
}

void Program::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	scene.update();

	// main SDL rendering
	SDL_GL_SwapWindow(window.window);
}

void Program::trackEvents()
{
	while(SDL_PollEvent(&e))
	{
		if(e.type == SDL_QUIT)
			running = false;

		// movement with WASD keys
		else if(e.type == SDL_KEYDOWN)
		{
			cameraFrontVector = camera.getNewFrontVector();

			switch(e.key.keysym.sym)
			{
				case SDLK_ESCAPE: running = false; break;

				case SDLK_w: 
					cameraPosition += camera.getSpeed() * cameraFrontVector;
					isMoving = true;
					break;
				case SDLK_s: 
					cameraPosition -= camera.getSpeed() * cameraFrontVector;
					isMoving = true;
					break;
				case SDLK_a: 
					cameraPosition -= glm::normalize(glm::cross(cameraFrontVector, camera.getUp())) * camera.getSpeed();
					isMoving = true;
					break;
				case SDLK_d: 
					cameraPosition += glm::normalize(glm::cross(cameraFrontVector, camera.getUp())) * camera.getSpeed();
					isMoving = true;
					break;
			}
		}

		// stop movement
		else if(e.type == SDL_KEYUP)
		{
			isMoving = false;
			cameraPosition = glm::vec3(0.0f);
		}

		// move camera according to mouse
		else if(e.type == SDL_MOUSEMOTION)
		{
			camera.processMouseMovement(e.motion.xrel, e.motion.yrel);
		}
	}
}
