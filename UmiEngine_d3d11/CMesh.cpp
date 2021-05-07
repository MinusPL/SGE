#include "CMesh.h"

void CMesh::Draw()
{
}

void CMesh::RecalculateNormals()
{
}

Vertex::Vertex(glm::vec3 position, glm::vec4 color):
	normal(), tangents(), uv()
{
	this->position = position;
	this->color = color;
}
