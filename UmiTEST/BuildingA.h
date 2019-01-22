#pragma once
#include <IL/il.h>

#include <Model.h>
#include <VisualObject.h>

class BuildingA : public VisualObject
{
public:
	BuildingA();
	~BuildingA();
	// Inherited via SGE_GameObject2D
	virtual void Update(GLfloat dt) override;
private:

};