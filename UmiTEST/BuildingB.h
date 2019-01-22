#pragma once
#include <IL/il.h>

#include <Model.h>
#include <VisualObject.h>

class BuildingB : public VisualObject
{
public:
	BuildingB();
	~BuildingB();
	// Inherited via SGE_GameObject2D
	virtual void Update(GLfloat dt) override;
private:

};
