#include "Scene.hh"

#include <GL/glew.h>

Scene::Scene() : cube()
{
}

Scene::~Scene()
{

}

void Scene::update(Camera& camera)
{
	// cube that is rotating around it's axis
	cube.render([&]()
	{
		cube.rot = glm::rotate(cube.rot, 0.1f, glm::vec3(0.0f, 1.0f, 0.0f));
	}, camera);
}
