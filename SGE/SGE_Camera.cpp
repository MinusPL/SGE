#include "SGE_Camera.h"

SGE_Camera::SGE_Camera(int mode)
{
	switch (mode)
	{
		case MODE_2D:
		{
			break;
		}
		case MODE_3D:
		{
			break;
		}
	}
}

SGE_Camera::SGE_Camera()
{

}

SGE_Camera::~SGE_Camera()
{
}

void SGE_Camera::Update()
{

}

void SGE_Camera::LookAt(glm::vec3 target)
{
	view = glm::lookAt(transform.Position(), target, transform.Up());
}

void SGE_Camera::Perspective(GLfloat fov, GLfloat aspectRatio, GLfloat nearPlane, GLfloat farPlane)
{
	this->projection = glm::perspective(fov, aspectRatio, nearPlane, farPlane);
	
}

void SGE_Camera::Orthographic(GLfloat left, GLfloat right, GLfloat top, GLfloat bottom, GLfloat zNear, GLfloat zFar)
{
	this->projection = glm::ortho(left, right, bottom, top, zNear, zFar);
}

glm::mat4 SGE_Camera::GetViewMat()
{
	return glm::lookAt(transform.Position(), transform.Position() + transform.Forward(), transform.Up());
}
