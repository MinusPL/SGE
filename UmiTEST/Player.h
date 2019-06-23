#pragma once
#include <IL/il.h>

#include <VisualObject.h>


//! Object representing player in game

/*!
Uses own player model (in this case a ball).
Can be moved by arrow keys
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