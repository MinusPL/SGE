#pragma once

#include <map>
#include <string>
#include "SGE_Shader.h"

class SGE_ResourceManager
{
public:
	static std::map<std::string, SGE_Shader> Shaders;
	static void LoadShader(const GLchar* vertexSource, const GLchar* fragmentSource, const GLchar* geometrySource, std::string name);
	static SGE_Shader& GetShader(std::string name);
private:
	SGE_ResourceManager() {};
	static SGE_Shader LoadShaderFromFile(const GLchar* vertexSource, const GLchar* fragmentSource, const GLchar* geometrySource);
};