#pragma once

#include <VisualObject.h>

class Grass : public VisualObject
{
public:
	Grass();
	~Grass();
	
	// Inherited via VisualObject
	virtual void Update(GLfloat dt) override;
};
