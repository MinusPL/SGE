#pragma once

#include "Transform.h"

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
	friend class Game;
public:
	Camera(int mode);
	Camera();
	~Camera();

	void Update();
	void LookAt(glm::vec3 target);

	void Perspective(GLfloat fov, GLfloat aspectRatio, GLfloat nearPlane, GLfloat farPlane);
	void Orthographic(GLfloat left, GLfloat right, GLfloat top, GLfloat bottom, GLfloat near_plane, GLfloat far_plane);

	Transform transform;

	glm::mat4 GetProjectionMatrix() { return projection; }
	glm::mat4 GetViewMat();

protected:
	glm::mat4 projection;
	glm::mat4 view;
};