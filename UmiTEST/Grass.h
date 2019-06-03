#pragma once

#include <VisualObject.h>

//! Grass bush placed randomly on scene.

/*!
It is using other shader than normal VisualObject, because it has transparent texture.
All bushes are created and placed randomly in Init(GLuint screen_width, GLuint screen_height) method of TestGame.
*/
class Grass : public VisualObject
{
public:
	//! Constructor

	/*!
	Load object model using assimp library.
	Load all object textures.
	Asign all textures to corresponding materials.
	Change shader from standard to standard_alpha.
	*/
	Grass();
	~Grass();
	
	//! Update all object logic.

	/*!
	\param dt - delta time calculated between frames.
	*/
	virtual void Update(GLfloat dt) override;
};
