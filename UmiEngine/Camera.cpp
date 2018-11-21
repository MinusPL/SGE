#include "Camera.h"
#include "Input.h"

Camera::Camera(int mode)
{

}

Camera::Camera()
{

}

Camera::~Camera()
{
}

void Camera::Update(GLfloat dt)
{
	float speed = 2.0f;
	if (Input::GetKey(Key::KEY_W))
	{
		this->transform.Position(this->transform.Position() + glm::vec3(speed * dt, 0.0f, 0.0f));
	}
	if (Input::GetKey(Key::KEY_S))
	{
		this->transform.Position(this->transform.Position() + glm::vec3(-speed * dt, 0.0f, 0.0f));
	}
	if (Input::GetKey(Key::KEY_A))
	{
		this->transform.Position(this->transform.Position() + glm::vec3(0.0f, 0.0f, -speed * dt));
	}
	if (Input::GetKey(Key::KEY_D))
	{
		this->transform.Position(this->transform.Position() + glm::vec3(0.0f, 0.0f, speed * dt));
	}
	if (Input::GetKey(Key::KEY_E))
	{
		this->transform.Position(this->transform.Position() + glm::vec3(0.0f, -speed * dt, 0.0f));
	}
	if (Input::GetKey(Key::KEY_Q))
	{
		this->transform.Position(this->transform.Position() + glm::vec3(0.0f, speed * dt, 0.0f));
	}
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
