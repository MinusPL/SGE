#pragma once

#pragma once
#include <IL/il.h>

#include <VisualObject.h>


//! Object representing player in game

/*!
Currently it is based on Cube primitive and uses it's own update method.
Player can be moved by arrow keys (now it isn't working properly and cube representing player doesn't move properly.
*/
class Water : public VisualObject
{
public:
	//! Constructor

	/*!
	Sets player material and texture.
	*/
	Water();
	~Water();

	//! Update all object logic.

	/*!
	Update player position and rotation based on user input.
	\param dt - delta time calculated between frames.
	*/
	virtual void Update(GLfloat dt) override;
private:

};