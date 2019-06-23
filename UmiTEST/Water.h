#pragma once

#pragma once
#include <IL/il.h>

#include <VisualObject.h>


//! Water surface for bucket

/*!
It uses different shader for handling transparency and reflections.
*/
class Water : public VisualObject
{
public:
	//! Constructor

	/*!
	Loads water model file and textures.
	*/
	Water();
	~Water();

	//! Update all object logic.

	/*!
	Update (not used by water for now).
	\param dt - delta time calculated between frames.
	*/
	virtual void Update(GLfloat dt) override;
private:

};