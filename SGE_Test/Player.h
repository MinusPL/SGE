#pragma once
#include <IL/il.h>

#include <Cube.h>

class Player : public Cube
{
public:
	Player();
	~Player();
	// Inherited via SGE_GameObject2D
	virtual void Update(GLfloat dt) override;
private:

};