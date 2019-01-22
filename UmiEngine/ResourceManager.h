#pragma once

#include <map>
#include <string>
#include <vector>
#include "Shader.h"
#include "Texture.h"

class ResourceManager
{
public:
	static std::map<std::string, Shader> Shaders;
	static std::map<std::string, Texture*> Textures;
	static void LoadShader(const GLchar* vertexSource, const GLchar* fragmentSource, const GLchar* geometrySource, std::string name);
	static void LoadTexture(const GLchar* texture, std::string name, TextureType type=TextureType::STANDARD);
	static void LoadCubeMap(std::vector<GLchar*> filenames, std::string name);
	static Shader* GetShader(std::string name);
	static Texture* GetTexture(std::string name);
private:
	ResourceManager() {};
	static Shader LoadShaderFromFile(const GLchar* vertexSource, const GLchar* fragmentSource, const GLchar* geometrySource);
	static Texture* LoadTextureFromFile(const GLchar* texture, TextureType type);
	static Texture* LoadCubeMapFromFile(std::vector<GLchar*> filenames);
};