#pragma once
#include <IL/il.h>

#include <Model.h>
#include <VisualObject.h>

class Player : public VisualObject
{
public:
	Player();
	~Player();
	// Inherited via SGE_GameObject2D
	virtual void Update(GLfloat dt) override;
private:

};