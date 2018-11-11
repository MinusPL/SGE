#pragma once

#include "PrimitiveVisual.h"

class Cube : public PrimitiveVisual
{
public:

	Cube();
	~Cube();
	// Inherited via PrimitiveVisual
	virtual void Update(GLfloat dt) override;

};