#include "Camera.h"

Camera::Camera(int mode)
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

Camera::Camera()
{

}

Camera::~Camera()
{
}

void Camera::Update()
{

}

void Camera::LookAt(glm::vec3 target)
{
	view = glm::lookAt(transform.Position(), target, transform.Up());
}

void Camera::Perspective(GLfloat fov, GLfloat aspectRatio, GLfloat nearPlane, GLfloat farPlane)
{
	this->projection = glm::perspective(fov, aspectRatio, nearPlane, farPlane);
	
}

void Camera::Orthographic(GLfloat left, GLfloat right, GLfloat top, GLfloat bottom, GLfloat zNear, GLfloat zFar)
{
	this->projection = glm::ortho(left, right, bottom, top, zNear, zFar);
}

glm::mat4 Camera::GetViewMat()
{
	return glm::lookAt(transform.Position(), transform.Position() + transform.Forward(), transform.Up());
}
