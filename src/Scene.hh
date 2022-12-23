#pragma once

#include "Cube.hh"
#include "Camera.hh"

class Scene
{
public:
	Scene();
	~Scene();
	void update(Camera& camera);
	Cube cube;
};
