#include "Scene.hh"

#include <GL/glew.h>

Scene::Scene(Camera& camera) : camera(camera),
	bunny("../resources/grass.png", "../resources/bunny.obj"),
	bunny2("../resources/rock.png", "../resources/bunny.obj"),
	dino("../resources/skin.png", "../resources/dino.obj"),
	dino2("../resources/fire.png", "../resources/dino.obj")
{
	bunny.translate(glm::vec3(5.0f, 0.0f, 0.0f));
	bunny2.translate(glm::vec3(5.0f, 0.0f, 8.0f));
	dino.translate(glm::vec3(1.0f, 0.0f, 5.0f));
	dino2.translate(glm::vec3(7.0f, 0.0f, 5.0f));
	
	for(int i = 0; i < 100; i++)
    {
        floor.emplace_back(std::make_unique<Cube>("../resources/grass.png", glm::vec3(0.2f, 0.2f, 0.2f)));
    }

    int xIndex = 0;
	int zIndex = 10;
	for(int i = 0; i < floor.size(); i++)
    {
		if(xIndex > 9)
		{
			xIndex = 0;
			zIndex--;
		}
        floor[i]->translate(glm::vec3(xIndex, -2.0f, zIndex));
		xIndex++;
    }
}

Scene::~Scene()
{
}

void Scene::update()
{
	bunny.render(camera);
	bunny2.render(camera);
	dino.render(camera);
	dino2.render(camera);
	
	// render the floor
	for(const auto& c : floor)
        c->render(camera);

	bunny.rotate(0.1f, glm::vec3(0.0f, 1.0f, 0.0f));
	dino.rotate(0.1f, glm::vec3(1.0f, 0.0f, 0.0f));
}
