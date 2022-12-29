#include "Scene.hh"

#include <GL/glew.h>

Scene::Scene(Camera& camera) : 
	camera(camera),
	bunny("../resources/bunny.obj"),
	bunny2("../resources/bunny.obj", glm::vec3(0.5f, 0.3f, 0.2f)),
	dino("../resources/dino.obj"),
	cube(glm::vec3(1.0f, 0.0f, 0.0f))
{
	bunny.translate(glm::vec3(5.0f, 1.0f, 0.0f));
	bunny2.translate(glm::vec3(-5.0f, -1.0f, 0.0f));
	dino.translate(glm::vec3(2.0f));
	cube.translate(glm::vec3(4.0f, 0.0f, 0.0f));
}

Scene::~Scene()
{
}

void Scene::update()
{
	bunny.render(camera);
	bunny2.render(camera);
	cube.render(camera);
	dino.render(camera);

	bunny.rotate(0.1f, glm::vec3(0.0f, 1.0f, 0.0f));
	bunny2.rotate(0.5f, glm::vec3(1.0f, 0.0f, 0.0f));
}
