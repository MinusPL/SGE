#pragma once

#include "SGE_Transform.h"

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

enum
{
	MODE_2D,
	MODE_3D
};

class SGE_Camera
{
	friend class SGE_Game;
public:
	SGE_Camera(int mode);
	SGE_Camera();
	~SGE_Camera();

	void Update();
	void LookAt(glm::vec3 target);

	void Perspective(GLfloat fov, GLfloat aspectRatio, GLfloat nearPlane, GLfloat farPlane);
	void Orthographic(GLfloat left, GLfloat right, GLfloat top, GLfloat bottom, GLfloat near_plane, GLfloat far_plane);

	SGE_Transform transform;

	glm::mat4 GetProjectionMatrix() { return projection; }
	glm::mat4 GetViewMat();

protected:
	glm::mat4 projection;
	glm::mat4 view;
};