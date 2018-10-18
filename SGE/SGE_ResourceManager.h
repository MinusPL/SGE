#pragma once

#include <map>
#include <string>

#include <GL/glew.h>

#include "SGE_Texture.h"
#include "SGE_Shader.h"


// A static singleton ResourceManager class that hosts several
// functions to load Textures and Shaders. Each loaded texture
// and/or shader is also stored for future reference by string
// handles. All functions and resources are static and no 
// public constructor is defined.
class SGE_ResourceManager
{
public:
	// Resource storage
	static std::map<std::string, SGE_Shader>    Shaders;
	static std::map<std::string, SGE_Texture2D> Textures;
	// Loads (and generates) a shader program from file loading vertex, fragment (and geometry) shader's source code. If gShaderFile is not nullptr, it also loads a geometry shader
	static SGE_Shader&   LoadShader(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *gShaderFile, std::string name);
	// Retrieves a stored sader
	static SGE_Shader&   GetShader(std::string name);
	// Loads (and generates) a texture from file
	static SGE_Texture2D& LoadTexture(const GLchar *file, GLboolean alpha, std::string name);
	// Retrieves a stored texture
	static SGE_Texture2D& GetTexture(std::string name);
	// Properly de-allocates all loaded resources
	static void      Clear();
private:
	// Private constructor, that is we do not want any actual resource manager objects. Its members and functions should be publicly available (static).
	SGE_ResourceManager() { }
	// Loads and generates a shader from file
	static SGE_Shader    loadShaderFromFile(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *gShaderFile = nullptr);
	// Loads a single texture from file
	static SGE_Texture2D loadTextureFromFile(const GLchar *file, GLboolean alpha);
};