#pragma once

#include "Cube.hh"
#include "Camera.hh"

#include <memory>

class Scene
{
public:
	Scene(Camera& camera);
	void update();
private:
	Camera& camera;
	Mesh bunny;
	Mesh bunny2;
	Mesh dino;
	Mesh dino2;
	Cube floor;
};

