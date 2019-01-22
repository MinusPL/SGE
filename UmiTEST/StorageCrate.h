#pragma once

#include <Cube.h>

class StorageCrate : public Cube
{
public:
	StorageCrate();
	virtual void Update(GLfloat dt);
	void setRotationDirection(glm::vec3 rotTemplate);
	void setRotationSpeed(float speed);
private:
	glm::vec3 rotationDirection;
	float rotSpeed = 0.0f;
};