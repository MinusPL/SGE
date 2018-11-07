#pragma once

#include <map>
#include <string>
#include "Shader.h"

class ResourceManager
{
public:
	static std::map<std::string, Shader> Shaders;
	static void LoadShader(const GLchar* vertexSource, const GLchar* fragmentSource, const GLchar* geometrySource, std::string name);
	static Shader& GetShader(std::string name);
private:
	ResourceManager() {};
	static Shader LoadShaderFromFile(const GLchar* vertexSource, const GLchar* fragmentSource, const GLchar* geometrySource);
};