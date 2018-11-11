#pragma once

#include <GL/glew.h>
#include <IL/il.h>
#include <IL/ilu.h>
#include <IL/ilut.h>
#include <string>

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

private:
	GLuint id;

	GLuint width, height;

	GLuint wrap_s, wrap_t;
	GLuint filter_min, filter_max;

	GLuint internal_format, image_format;
};