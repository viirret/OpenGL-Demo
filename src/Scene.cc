#include "Scene.hh"

#include <GL/glew.h>

Scene::Scene(Camera& camera) : camera(camera),
	bunny("../resources/grass.png", "../resources/bunny.obj"),
	bunny2("../resources/rock.png", "../resources/bunny.obj"),
	dino("../resources/skin.png", "../resources/dino.obj"),
	dino2("../resources/fire.png", "../resources/dino.obj"),
	floor("../resources/grass.png")
{
	bunny.translate(glm::vec3(5.0f, 0.0f, 0.0f));
	bunny2.translate(glm::vec3(5.0f, 0.0f, 8.0f));
	dino.translate(glm::vec3(1.0f, 0.0f, 5.0f));
	dino2.translate(glm::vec3(7.0f, 0.0f, 5.0f));

	floor.translate(glm::vec3(0.0f, -1.0f, 0.0f));
	floor.scale(glm::vec3(20.0f, 0.1f, 20.0f));
}

void Scene::update()
{
	bunny.render(camera);
	bunny2.render(camera);
	dino.render(camera);
	dino2.render(camera);
	floor.render(camera);

	bunny.rotate(0.1f, glm::vec3(0.0f, 1.0f, 0.0f));
	dino.rotate(0.1f, glm::vec3(1.0f, 0.0f, 0.0f));
}
