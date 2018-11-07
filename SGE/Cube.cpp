#include "Cube.h"

Cube::Cube()
{

	//front
	mesh.vertices.push_back(glm::vec3(0.5, 0.5, 0.5));
	mesh.vertices.push_back(glm::vec3(-0.5, 0.5, 0.5));
	mesh.vertices.push_back(glm::vec3(-0.5, -0.5, 0.5));
	mesh.vertices.push_back(glm::vec3(0.5, -0.5, 0.5));

	mesh.uvs.push_back(glm::vec2(1, 1));
	mesh.uvs.push_back(glm::vec2(0, 1));
	mesh.uvs.push_back(glm::vec2(0, 0));
	mesh.uvs.push_back(glm::vec2(1, 0));

	//back
	mesh.vertices.push_back(glm::vec3(0.5, 0.5, -0.5));
	mesh.vertices.push_back(glm::vec3(0.5, -0.5, -0.5));
	mesh.vertices.push_back(glm::vec3(-0.5, -0.5, -0.5));
	mesh.vertices.push_back(glm::vec3(-0.5, 0.5, -0.5));

	mesh.uvs.push_back(glm::vec2(1, 1));
	mesh.uvs.push_back(glm::vec2(1, 0));
	mesh.uvs.push_back(glm::vec2(0, 0));
	mesh.uvs.push_back(glm::vec2(0, 1));
	//right
	mesh.vertices.push_back(glm::vec3(0.5, 0.5, -0.5));
	mesh.vertices.push_back(glm::vec3(0.5, 0.5, 0.5));
	mesh.vertices.push_back(glm::vec3(0.5, -0.5, 0.5));
	mesh.vertices.push_back(glm::vec3(0.5, -0.5, -0.5));

	mesh.uvs.push_back(glm::vec2(1, 0));
	mesh.uvs.push_back(glm::vec2(1, 1));
	mesh.uvs.push_back(glm::vec2(0, 1));
	mesh.uvs.push_back(glm::vec2(0, 0));
	//left
	mesh.vertices.push_back(glm::vec3(-0.5, 0.5, 0.5));
	mesh.vertices.push_back(glm::vec3(-0.5, 0.5, -0.5));
	mesh.vertices.push_back(glm::vec3(-0.5, -0.5, -0.5));
	mesh.vertices.push_back(glm::vec3(-0.5, -0.5, 0.5));

	mesh.uvs.push_back(glm::vec2(1, 1));
	mesh.uvs.push_back(glm::vec2(1, 0));
	mesh.uvs.push_back(glm::vec2(0, 0));
	mesh.uvs.push_back(glm::vec2(0, 1));
	//up
	mesh.vertices.push_back(glm::vec3(0.5, 0.5, -0.5));
	mesh.vertices.push_back(glm::vec3(-0.5, 0.5, -0.5));
	mesh.vertices.push_back(glm::vec3(-0.5, 0.5, 0.5));
	mesh.vertices.push_back(glm::vec3(0.5, 0.5, 0.5));

	mesh.uvs.push_back(glm::vec2(1, 0));
	mesh.uvs.push_back(glm::vec2(0, 0));
	mesh.uvs.push_back(glm::vec2(0, 1));
	mesh.uvs.push_back(glm::vec2(1, 1));
	//bottom
	mesh.vertices.push_back(glm::vec3(0.5, -0.5, 0.5));
	mesh.vertices.push_back(glm::vec3(-0.5, -0.5, 0.5));
	mesh.vertices.push_back(glm::vec3(-0.5, -0.5, -0.5));
	mesh.vertices.push_back(glm::vec3(0.5, -0.5, -0.5));

	mesh.uvs.push_back(glm::vec2(1, 1));
	mesh.uvs.push_back(glm::vec2(1, 0));
	mesh.uvs.push_back(glm::vec2(0, 0));
	mesh.uvs.push_back(glm::vec2(0, 1));

	for (size_t i = 0; i < 6; i++)
	{
		mesh.indices.push_back(i * 4);
		mesh.indices.push_back(i * 4 + 1);
		mesh.indices.push_back(i * 4 + 2);

		mesh.indices.push_back(i * 4);
		mesh.indices.push_back(i * 4 + 2);
		mesh.indices.push_back(i * 4 + 3);
	}

	mesh.RecalculateNormals();
	mesh.CreateMesh();
}


Cube::~Cube()
{

}