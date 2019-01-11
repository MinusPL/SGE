#pragma once
#include "Light.h"
#include "Shader.h"


class DirectionalLight : public Light
{
public:
	glm::vec3 direction;
	void ApplyToShader(Shader* shader);
};