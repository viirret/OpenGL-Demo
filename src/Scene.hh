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
	Mesh dino;
	Cube floor;

	std::vector<std::unique_ptr<Cube>> smiley;
};

