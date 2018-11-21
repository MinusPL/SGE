#pragma once

#include "PrimitiveVisual.h"

class Plane : public PrimitiveVisual
{
public:

	Plane();
	~Plane();
	// Inherited via PrimitiveVisual
	virtual void Update(GLfloat dt) override;
};