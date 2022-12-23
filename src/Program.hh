#pragma once

#include "Shader.hh"
#include "Window.hh"
#include "Cube.hh"
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
	Scene scene;
	Camera camera;

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
