#pragma once

#include <GL/glew.h>
#include <IL/il.h>
#include <IL/ilu.h>
#include <IL/ilut.h>
#include <string>
#include <vector>

enum class TextureType
{
	STANDARD,
	CUBEMAP
};

class Texture
{
public:
	Texture();
	~Texture();

	void BindTexture();

	GLuint GetWidth();
	GLuint GetHeight();

	GLuint GetInternalFormat();
	//void SetInternalFormat(GLuint format);

	GLuint GetImageFormat();
	//void SetImageFormat(GLuint format);

	void LoadFromFile(GLchar* filename);
	void LoadCubemapFromFile(std::vector<GLchar*> filenames);

private:
	GLuint id;

	GLuint width, height;

	GLuint wrap_s, wrap_t;
	GLuint filter_min, filter_max;

	GLuint internal_format, image_format;
};