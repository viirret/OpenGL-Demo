#pragma once

#include "Cube.hh"
#include "Camera.hh"

class Scene
{
public:
	Scene(Camera& camera);
	~Scene();
	void update();
private:
	Camera& camera;
	Mesh bunny;
	Mesh bunny2;
	Mesh dino;
	Cube cube;
};

