#pragma once

#include "GameObject.h"
#include "Shader.h"
#include "Mesh.h"
#include "Material.h"

#include <vector>

class PrimitiveVisual : public GameObject
{
public:
	Shader* shader;
	std::vector<Mesh*> meshes;
	Material material;


	virtual void Draw() override;

	PrimitiveVisual(ShaderType shaderType = STANDARD);
	~PrimitiveVisual();
	float rot = 0.0f;
};