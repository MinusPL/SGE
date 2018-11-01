#include "SGE_ResourceManager.h"

#include <fstream>
#include <sstream>
#include <iostream>

std::map<std::string, SGE_Shader> SGE_ResourceManager::Shaders;

void SGE_ResourceManager::LoadShader(const GLchar * vertexSource, const GLchar * fragmentSource, const GLchar * geometrySource, std::string name)
{
	Shaders[name] = LoadShaderFromFile(vertexSource, fragmentSource, geometrySource);
}

SGE_Shader & SGE_ResourceManager::GetShader(std::string name)
{
	if(Shaders.count(name) <= 0) throw "Shader doesn't exists!";
	return Shaders.at(name);
}

SGE_Shader SGE_ResourceManager::LoadShaderFromFile(const GLchar * vertexSource, const GLchar * fragmentSource, const GLchar * geometrySource)
{
	std::string vertexCode;
	std::string fragmentCode;
	std::string geometryCode;
	try
	{
		// Open files
		std::ifstream vertexShaderFile(vertexSource);
		std::ifstream fragmentShaderFile(fragmentSource);
		std::stringstream vertexStream, fragmentStream;
		// Read file's buffer contents into streams
		vertexStream << vertexShaderFile.rdbuf();
		fragmentStream << fragmentShaderFile.rdbuf();
		// close file handlers
		vertexShaderFile.close();
		fragmentShaderFile.close();
		// Convert stream into string
		vertexCode = vertexStream.str();
		fragmentCode = fragmentStream.str();
		// If geometry shader path is present, also load a geometry shader
		if (geometrySource != nullptr)
		{
			std::ifstream geometryShaderFile(geometrySource);
			std::stringstream geometryStream;
			geometryStream << geometryShaderFile.rdbuf();
			geometryShaderFile.close();
			geometryCode = geometryStream.str();
		}
	}
	catch (std::exception e)
	{
		std::cout << "ERROR::SHADER: Failed to read shader files" << std::endl;
	}
	const GLchar *vertexShaderCode = vertexCode.c_str();
	const GLchar *fragmentShaderCode = fragmentCode.c_str();
	const GLchar *geometryShaderCode = geometryCode.c_str();
	// 2. Now create shader object from source code
	SGE_Shader shader;
	shader.Compile(vertexShaderCode, fragmentShaderCode, geometrySource != nullptr ? geometryShaderCode : nullptr);
	return shader;
}
