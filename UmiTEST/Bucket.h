#pragma once
#include <IL/il.h>

#include <VisualObject.h>


//! Bucket object.

class Bucket : public VisualObject
{
public:
	//! Constructor

	Bucket();
	~Bucket();

	//! Update all object logic.

	/*!
	\param dt - delta time calculated between frames.
	*/
	virtual void Update(GLfloat dt) override;
private:

};