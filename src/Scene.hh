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
	//std::vector<Cube> floor;

	// random test cubes
	//Cube cube;
	Cube cube2;
};

