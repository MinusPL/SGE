#pragma once

#include "GameObject.h"
#include "Shader.h"
#include "Mesh.h"
#include "Material.h"

class VisualObject : public GameObject
{
public:
	Shader shader;
	Mesh mesh;
	Material material;

	
	virtual void Draw() override;

	VisualObject(ShaderType shaderType = STANDARD);
	~VisualObject();
	float rot = 0.0f;
};