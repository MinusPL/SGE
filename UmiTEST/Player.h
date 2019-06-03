#pragma once
#include <IL/il.h>

#include <VisualObject.h>


//! Object representing player in game

/*!
Currently it is based on Cube primitive and uses it's own update method.
Player can be moved by arrow keys (now it isn't working properly and cube representing player doesn't move properly.
*/
class Player : public VisualObject
{
public:
	//! Constructor

	/*!
	Sets player material and texture.
	*/
	Player();
	~Player();

	//! Update all object logic.

	/*!
	Update player position and rotation based on user input.
	\param dt - delta time calculated between frames.
	*/
	virtual void Update(GLfloat dt) override;
private:

};