#pragma once

#include <glm/glm.hpp>
#include <vector>

struct Vertex
{
	glm::vec3 position;
	glm::vec4 color;
	glm::vec2 normal;
	glm::vec2 uv;
	glm::vec3 tangents;
	Vertex(glm::vec3 position, glm::vec4 color);
};

class CMesh
{
public:
	std::vector<Vertex> vertices;
	std::vector<uint32_t> indices;
	void RecalculateNormals();

	virtual bool Create() = 0;
	virtual void Draw() = 0;
};