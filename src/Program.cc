#include "Program.hh"

#include <GL/glew.h>

Program::Program() : 
	running(true), window(""), scene(),
	camera(
			glm::lookAt(
			glm::vec3(0, 0, 10),
			glm::vec3(0, 0, 0),
			glm::vec3(0, 1, 0)
	),
			glm::perspective(
			glm::radians(45.0f), 
			4.0f / 3.0f,
			0.1f,
			100.0f
	))
{
	// give a nice background
	glClearColor(0.0f, 0.0f, 0.4f, 1.0f);
	while(running)
	{
		update();
	}
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
	{
		// get copy of the old view
		glm::mat4 view = camera.view;

		// update the camera's position using the velocity
		view[3][0] += velocity.x * elapsedTime;
		view[3][2] += velocity.z * elapsedTime;

		// smooth out the camera's movement using a low-pass filter
		const float alpha = 0.1f;
		view[3][0] = view[3][0] * (1.0f - alpha) + camera.view[3][0] * alpha;
		view[3][2] = view[3][2] * (1.0f - alpha) + camera.view[3][2] * alpha;

		camera.setView(view);
	}
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
	glClear(GL_COLOR_BUFFER_BIT);

	scene.update(camera);

	// main SDL rendering
	SDL_GL_SwapWindow(window.window);
}

void Program::trackEvents()
{
	while(SDL_PollEvent(&e))
	{
		if(e.type == SDL_QUIT)
			running = false;

		else if(e.type == SDL_KEYDOWN)
		{
			switch(e.key.keysym.sym)
			{
				case SDLK_ESCAPE: running = false; break;
				case SDLK_w: 
					velocity.z += 0.001f * elapsedTime; 
					isMoving = true;
					break;
				case SDLK_s: 
					velocity.z -= 0.001f * elapsedTime; 
					isMoving = true;
					break;
				case SDLK_a: 
					velocity.x -= 0.001f * elapsedTime;
					isMoving = true;
					break;
				case SDLK_d: 
					velocity.x += 0.001f * elapsedTime; 
					isMoving = true;
					break;
			}
		}

		// stop movement
		else if(e.type == SDL_KEYUP)
		{
			velocity = glm::vec3(0.0f, 0.0f, 0.0f);
			isMoving = false;
		}
	}
}
