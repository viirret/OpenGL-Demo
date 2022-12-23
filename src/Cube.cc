#include "Cube.hh"

#include <GL/glew.h>

#include <vector>

Cube::Cube(std::vector<float>&& vertexBufferData)
{
	create(vertexBufferData);
}

Cube::Cube(std::vector<float>& vertexBufferData)
{
	create(vertexBufferData);
}

Cube::Cube() 
{ 
	create(standardVertexBufferData); 
}

Cube::Cube(float offset, int axel)
{
	auto copy = standardVertexBufferData;

	for(int i = 0; i < copy.size(); i++)
		if(i % axel == 0)
			copy[i] += offset;

	create(copy);
}

void Cube::render(const std::function<void()>& f, Camera& camera)
{
	f();

	model = tra * rot;
	
	glUniformMatrix4fv(Mesh::material.getmmID(), 1, GL_FALSE, &model[0][0]);

	// this is very hacky fix
	// I'll get rid of this in future, but this was the easies to just get working
	glUniformMatrix4fv(Mesh::material.getvmID(), 1, GL_FALSE, &camera.view[0][0]);
	glUniformMatrix4fv(Mesh::material.getpmID(), 1, GL_FALSE, &camera.projection[0][0]);

	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 36);
}

void Cube::create(std::vector<float>& vertexBufferData)
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	unsigned int vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glBufferData(GL_ARRAY_BUFFER, vertexBufferData.size() * sizeof(std::vector<float>), &vertexBufferData[0], GL_STATIC_DRAW);

	unsigned int vcb;
	glGenBuffers(1, &vcb);
	glBindBuffer(GL_ARRAY_BUFFER, vcb);

	glBufferData(GL_ARRAY_BUFFER, sizeof(colorBufferData), colorBufferData, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, vcb);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}


