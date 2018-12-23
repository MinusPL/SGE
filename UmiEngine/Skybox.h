#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>

#include "Shader.h"
#include "Texture.h"


class Skybox
{
public:
	Texture* texture;
	Skybox();
	~Skybox();

	void Draw();
private:
	Shader* shader;
	std::vector<glm::vec3> vertices;
	unsigned int sVAO, sVBO;
};