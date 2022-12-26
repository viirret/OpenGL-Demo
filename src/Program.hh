#pragma once

#include "Shader.hh"
#include "Window.hh"
#include "Camera.hh"
#include "Scene.hh"

class Program
{
public:
	Program();
private:
	void update();
	void render();
	void trackEvents();
	void updateCamera();
	void updateTime();

	bool running;
	Window window;
	Camera camera;
	Scene scene;

	SDL_Event e;

	// camera's velocity
	glm::vec3 velocity = glm::vec3(0.0f, 0.0f, 0.0f);
	bool isMoving = false;

	// variables for updating time
	const int FPS = 1000 / 60; // 60 FPS
	int lastTime = SDL_GetTicks();
	int currentTime;
	int elapsedTime;
};
