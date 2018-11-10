#pragma once

#include "GameObject.h"
#include "Shader.h"
#include "Model.h"
#include "Material.h"

class VisualObject : public GameObject
{
public:
	Shader shader;
	std::vector<Mesh>meshes;
	Model model;
	Material material;

	
	virtual void Draw() override;

	VisualObject(GLchar* model_file, ShaderType shaderType = STANDARD);
	~VisualObject();
	float rot = 0.0f;
};