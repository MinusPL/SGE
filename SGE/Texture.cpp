#include "Texture.h"

Texture::Texture() :
	width(0), height(0), internal_format(GL_RGBA), image_format(GL_RGBA), wrap_s(GL_REPEAT), wrap_t(GL_REPEAT), filter_min(GL_LINEAR), filter_max(GL_LINEAR)
{
	glGenTextures(1, &this->id);
}

Texture::~Texture()
{

}

void Texture::BindTexture()
{
	glBindTexture(GL_TEXTURE_2D, this->id);
}

GLuint Texture::GetWidth()
{
	return this->width;
}

GLuint Texture::GetHeight()
{
	return this->height;
}

GLuint Texture::GetInternalFormat()
{
	return this->internal_format;
}

GLuint Texture::GetImageFormat()
{
	return this->image_format;
}


void Texture::LoadFromFile(GLchar* filename)
{
	ILuint imageName;
	ilGenImages(1, &imageName);
	ilBindImage(imageName);
	ilLoadImage(filename);

	this->width = ilGetInteger(IL_IMAGE_WIDTH);
	this->height = ilGetInteger(IL_IMAGE_HEIGHT);

	ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);
	glBindTexture(GL_TEXTURE_2D, this->id);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->width, this->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, ilGetData());

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, this->wrap_s);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, this->wrap_t);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, this->filter_min);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, this->filter_max);

	glBindTexture(GL_TEXTURE_2D, 0);
	ilDeleteImages(1, &imageName);
}
