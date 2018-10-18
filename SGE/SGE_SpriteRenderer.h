#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include "SGE_Shader.h"
#include "SGE_Texture.h"

class SGE_SpriteRenderer
{
public:
	SGE_SpriteRenderer(SGE_Shader &shader);
	~SGE_SpriteRenderer();

	void DrawSprite(SGE_Texture2D &texture, glm::vec2 position,
		glm::vec2 size = glm::vec2(10, 10), GLfloat rotate = 0.0f,
		glm::vec3 color = glm::vec3(1.0f));
private:
	SGE_Shader shader;
	GLuint quadVAO;

	void initRenderData();
};