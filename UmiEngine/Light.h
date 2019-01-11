#pragma once

#include <glm\glm.hpp>
#include <glm\gtc\type_ptr.hpp>


class Light
{
public:
	glm::vec3 diffuse;
	glm::vec3 ambient;
	glm::vec3 specular;
};