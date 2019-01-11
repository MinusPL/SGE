#pragma once

#include <vector>

#include "Shader.h"
#include "DirectionalLight.h"


class LightManager
{
public:
	static void AddDirectionalLight(DirectionalLight* light)
	{
		dirLights.push_back(light);
	}

	//static void AddPointLight(PointLight* light) {
	//	pointLights.push_back(light);
	//}

	static glm::mat4 GetDirLightSpaceMatrix();

	static void ApplyToShader(Shader* shader);
private:
	static std::vector<DirectionalLight*> dirLights;
	//static std::vector<PointLight*> pointLights;

	LightManager();
	~LightManager();
};