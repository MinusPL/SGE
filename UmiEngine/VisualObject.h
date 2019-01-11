#pragma once

#include "GameObject.h"
#include "Shader.h"
#include "Model.h"
#include "Material.h"
#include "LightManager.h"

class VisualObject : public GameObject
{
public:
	Shader* shader;
	Model model;
	
	virtual void Draw() override;
	virtual void DrawShadow() override;

	VisualObject(GLchar* model_file, ShaderType shaderType = STANDARD);
	~VisualObject();

	float rot = 0.0f;
	bool receiveShadows = false;
};