#include "CCamera.h"

CCamera::CCamera():
    yaw(0.0), pitch(0.0), projection(), view()
{

}

void CCamera::Update(float dt)
{
}

void CCamera::LookAt(glm::vec3 target)
{
	view = glm::lookAt(transform.Position(), target, transform.Up());
}

void CCamera::Perspective(float fov, float aspectRatio, float nearPlane, float farPlane)
{
	this->projection = glm::perspective(fov, aspectRatio, nearPlane, farPlane);

}

void CCamera::Orthographic(float left, float right, float top, float bottom, float zNear, float zFar)
{
	this->projection = glm::ortho(left, right, bottom, top, zNear, zFar);
}

glm::mat4 CCamera::GetViewMat()
{
	return glm::lookAt(transform.Position(), transform.Position() + transform.Forward(), transform.Up());
}