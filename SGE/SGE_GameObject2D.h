#pragma once

#include "SGE_GameObject.h"
#include "SGE_Shader.h"
#include "SGE_Mesh.h"

class SGE_GameObject2D : public SGE_GameObject
{
public:
	SGE_Shader shader;
	SGE_Mesh mesh;
	
	virtual void Draw() override;
	virtual void Update() override;

	SGE_GameObject2D(ShaderType shaderType = STANDARD);
	~SGE_GameObject2D();
};