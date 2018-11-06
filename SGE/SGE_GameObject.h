#pragma once



#include "SGE_Transform.h"

enum ShaderType {STANDARD, STANDARD_2D};

class SGE_GameObject
{
public:
	SGE_Transform transform;

	SGE_GameObject();
	~SGE_GameObject();

	virtual void Update() = 0;
	virtual void Draw() = 0;
};