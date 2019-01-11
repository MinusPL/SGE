#pragma once



#include "Transform.h"
#include <gl/glew.h>

enum ShaderType {STANDARD, STANDARD_ALPHA, STANDARD_SHADELESS};

class GameObject
{
public:
	Transform transform;

	GameObject();
	~GameObject();

	virtual void Update(GLfloat dt) = 0;
	virtual void Draw() = 0;
	virtual void DrawShadow() = 0;
};