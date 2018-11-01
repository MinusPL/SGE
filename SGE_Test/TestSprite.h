#pragma once

#include "SGE_GameObject.h"

class TestSprite : public SGE_GameObject
{
	// Inherited via SGE_GameObject
	virtual void Update() override;
	virtual void Draw() override;
};