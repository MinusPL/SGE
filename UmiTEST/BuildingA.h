#pragma once
#include <IL/il.h>

#include <Model.h>
#include <VisualObject.h>

class BuildingA : public VisualObject
{
public:
	//! Constructor

	/*!
	Load object model using assimp library.
	Load all object textures.
	Asign all textures to corresponding materials.
	*/
	BuildingA();
	~BuildingA();
	//! Update all object logic.

	/*!
	\param dt - delta time calculated between frames.
	*/
	virtual void Update(GLfloat dt) override;
private:

};