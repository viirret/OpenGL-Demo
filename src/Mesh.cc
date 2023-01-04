#include "Mesh.hh"

// default constructor for created objects
Mesh::Mesh(const glm::vec3& color, const std::string& texturePath, const std::string& objPath)
	: 	material("../shaders/vertex.vert", "../shaders/frag.frag"),
		transform(),
		objLoader(objPath),
		color(color),
		tex(texturePath)
{
	createObject();
}

// same constructor but with 1, 1, 1 color
Mesh::Mesh(const std::string& texturePath, const std::string& objPath) 
	: Mesh(glm::vec3(1.0f, 1.0f, 1.0f), texturePath, objPath)
{
}

// constructor that Cube objects call
Mesh::Mesh(const glm::vec3& color, const std::string& texturePath)
	: 	material("../shaders/vertex.vert", "../shaders/frag.frag"),
		transform(),
		objLoader(),
		color(color),
		tex(texturePath)
{
}

void Mesh::createObject()
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// vertexData
	unsigned int vertexVBO;
	glGenBuffers(1, &vertexVBO);
	glBindBuffer(GL_ARRAY_BUFFER, vertexVBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), vertices.data(), GL_STATIC_DRAW);

	// texture coord data
	unsigned int uvVBO;
	glGenBuffers(1, &uvVBO);
	glBindBuffer(GL_ARRAY_BUFFER, uvVBO);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(1);
	glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), uvs.data(), GL_STATIC_DRAW);

	// normalData
	unsigned int normalVBO;
	glGenBuffers(1, &normalVBO);
	glBindBuffer(GL_ARRAY_BUFFER, normalVBO);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(2);
	glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3), normals.data(), GL_STATIC_DRAW);

	// Generate an EBO and bind it.
	unsigned int ebo;
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

	// Copy the indices to the EBO.
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

	// Unbind the VAO and VBOs.
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

// transform functions 
// this class could have inherited from Transform, but I chose to go like this
void Mesh::translate(const glm::vec3& position)
{
	transform.translate(position);
}

void Mesh::rotate(float speed, const glm::vec3& direction)
{
	transform.rotate(speed, direction);
}

void Mesh::scale(const glm::vec3& scale)
{
	transform.scale(scale);
}

// default rendering
void Mesh::render(Camera& camera)
{
	renderOverrider(camera, [this]()
	{
		glDrawElements(GL_TRIANGLES, objLoader.getIndices().size(), GL_UNSIGNED_INT, nullptr);
	});
}

void Mesh::renderOverrider(Camera& camera, std::function<void()> func)
{
	// calculate mvp
	glm::mat4 mvp = camera.getProjection() * camera.getView() * transform.getModel();

	// use shader program
	material.use();

	// bind texture
	if(tex.path != "")
	{	
		glBindTexture(GL_TEXTURE_2D, tex.texture);
	}
	else
	{
		DBG_LOG("NO PATH");
	}

	// Bind the VAO
	glBindVertexArray(vao);

	// set mvp
	glUniformMatrix4fv(material.getMvp(), 1, GL_FALSE, &mvp[0][0]);

	// set color
	glUniform4f(material.getColor(), color.x, color.y, color.z, 0.0f);
	
	// Draw the mesh
	func();

	// Unbind the VAO
	glBindVertexArray(0);

	// unset material
	glUseProgram(0);
}

