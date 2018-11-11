#pragma once



#include "Transform.h"
#include <gl/glew.h>

enum ShaderType {STANDARD, STANDARD_2D};

class GameObject
{
public:
	Transform transform;

	GameObject();
	~GameObject();

	virtual void Update(GLfloat dt) = 0;
	virtual void Draw() = 0;
};