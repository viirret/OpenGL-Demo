#include "Scene.hh"

#include <GL/glew.h>

Scene::Scene(Camera& camera) : 
	camera(camera),

	/*
	floor({
		Cube(0.7f)
	}),

	cube(),
	*/
	cube2(0.5f)
{
	//cube.translate(glm::vec3(2.0f, 1.0f, 4.0f));

	cube2.translate(glm::vec3(3.0f, 0.0f, 1.0f));

	//floor[0].translate(glm::vec3(2.0f, 1.0f, 2.0f));
}

Scene::~Scene()
{
}

void Scene::update()
{
	//cube2.rotate(0.1f, glm::vec3(0.0f, 1.0f, 0.0f));

	//for(auto& c : floor)
	//c.render(camera);

	//cube.render(camera);
	cube2.render(camera);
}
