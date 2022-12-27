#include "Scene.hh"

#include <GL/glew.h>

Scene::Scene(Camera& camera) : 
	camera(camera),
	bunny("../resources/bunny.obj")
{
	bunny.translate(glm::vec3(0.0f, -1.0f, 8.0f));
}

Scene::~Scene()
{
}

void Scene::update()
{
	bunny.render(camera);
	bunny.rotate(0.1f, glm::vec3(0.0f, 1.0f, 0.0f));
}
