#include "Scene.hh"

#include <GL/glew.h>

Scene::Scene(Camera& camera) : camera(camera),
	bunny("../resources/skin.png", "../resources/bunny.obj"),
	dino("../resources/fire.png", "../resources/dino.obj"),
	floor("../resources/grass.png")
{
	bunny.translate(glm::vec3(3.0f, -0.5f, 7.0f));
	dino.translate(glm::vec3(-1.0f, -0.5f, 7.0f));
	dino.scale(glm::vec3(2.0f));

	floor.translate(glm::vec3(0.0f, -1.0f, 0.0f));
	floor.scale(glm::vec3(20.0f, 0.1f, 20.0f));

	for(int i = 0; i < 7; i++)
		smiley.emplace_back(std::make_unique<Cube>("../resources/rock.png"));

	smiley[0]->translate(glm::vec3(-2.0f, 2.0f, -1.0f));
	smiley[1]->translate(glm::vec3(0.0f, 0.0f, -1.0f));
	smiley[2]->translate(glm::vec3(2.0f, 0.0f, -1.0f));
	smiley[3]->translate(glm::vec3(4.0f, 0.0f, -1.0f));
	smiley[4]->translate(glm::vec3(6.0f, 2.0f, -1.0f));
	smiley[5]->translate(glm::vec3(0.5f, 6.5f, -1.0f));
	smiley[6]->translate(glm::vec3(3.5f, 6.5f, -1.0f));
}

void Scene::update()
{
	bunny.render(camera);
	dino.render(camera);
	floor.render(camera);

	for(auto& s : smiley)
		s->render(camera);
}
