#include "ObjLoader.hh"

#include <iostream>
#include <fstream>
#include <sstream>

// loads an OBJ file and returns true on success, false on failure.
bool ObjLoader::load(const std::string& filepath)
{
	std::ifstream file(filepath);
	if(!file.is_open())
	{
		std::cerr << "Error: failed to open OBJ file " << filepath << std::endl;
		return false;
	}

	std::string line;
	while(std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string type;
		iss >> type;
		if(type == "v")
		{
			glm::vec3 vertex;
			iss >> vertex.x >> vertex.y >> vertex.z;
			vertices.push_back(vertex);
		}
		else if(type == "vn")
		{
			glm::vec3 normal;
			iss >> normal.x >> normal.y >> normal.z;
			normals.push_back(normal);
		}
		else if(type == "vt")
		{
			glm::vec2 texCoord;
			iss >> texCoord.x >> texCoord.y;
			uvs.push_back(texCoord);
		}
		else if(type == "f")
		{
			parseFace(line.substr(2), indices);
		}
	}

	return true;
}


const std::vector<glm::vec3>& ObjLoader::getVertices() const { return vertices; }

const std::vector<glm::vec3>& ObjLoader::getNormals() const { return normals; }

const std::vector<glm::vec2>& ObjLoader::getUVs() const { return uvs; }

const std::vector<unsigned int>& ObjLoader::getIndices() const { return indices; }

// parses a face line from the OBJ file and stores the indices in the given vector.
void ObjLoader::parseFace(const std::string& face, std::vector<unsigned int>& indices)
{
	std::istringstream iss(face);
	std::string index;
	while(iss >> index)
	{
		// parse the vertex index.
		std::size_t vertexIndex = std::stoul(index);
		if(vertexIndex > 0)
		{
			// OBJ indices are 1-based, so subtract 1 to convert to 0-based.
			vertexIndex -= 1;
		}
		else
		{
			// OBJ indices can be negative to refer to vertices relative to the end of the list.
			vertexIndex = vertices.size() + vertexIndex;
		}
		indices.push_back(vertexIndex);

		// parse the optional texture coordinate and normal indices.
		if(iss.peek() == '/')
		{
			iss.ignore();
			if(std::isdigit(iss.peek()))
			{
				iss >> index;
				std::size_t uvIndex = std::stoul(index);
				if(uvIndex > 0)
				{
					// OBJ indices are 1-based, so subtract 1 to convert to 0-based.
					uvIndex -= 1;
				}
				else
				{
					// OBJ indices can be negative to refer to elements relative to the end of the list.
					uvIndex = uvs.size() + uvIndex;
				}
				indices.push_back(uvIndex);
			}
			if(iss.peek() == '/')
			{
				iss.ignore();
				iss >> index;
				std::size_t normalIndex = std::stoul(index);
				if (normalIndex > 0)
				{
					// OBJ indices are 1-based, so subtract 1 to convert to 0-based.
					normalIndex -= 1;
				}
				else
				{
					// OBJ indices can be negative to refer to elements relative to the end of the list.
					normalIndex = normals.size() + normalIndex;
				}
				indices.push_back(normalIndex);
			}
		}
	}
}
