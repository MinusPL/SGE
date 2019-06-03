#pragma once

#include <Cube.h>

//! Storage crate object (one rotating in air)
class StorageCrate : public Cube
{
public:
	//! Constructor

	/*!
	Set storage crate material and texture.
	*/
	StorageCrate();

	//! Update all object logic.

	/*!
	Update storage crate rotation.
	\param dt - delta time calculated between frames.
	*/
	virtual void Update(GLfloat dt);
	//! Set object rotation direction.

	/*!
	\param rotTemplate - glm::vec3 with float values for rotation in each axis.
	*/
	void setRotationDirection(glm::vec3 rotTemplate);
	//! Set rotation speed.

	/*!
	\param speed - defines speed of rotation in all axes.
	*/
	void setRotationSpeed(float speed);
private:
	glm::vec3 rotationDirection;
	float rotSpeed = 0.0f;
};