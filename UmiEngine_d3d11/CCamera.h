#pragma once

#include <glm/glm.hpp>
#include "CTransform.h"



class CCamera
{
private:

protected:
	glm::mat4 projection;
	glm::mat4 view;
	double yaw;
	double pitch;
public:
	//! Constructor for Camera
	CCamera();

	//! Destructor
	~CCamera();

	void Update(float dt);

	//! Set camera to look at position.

	/*!
	\param target - position at which camera will look.
	*/
	void LookAt(glm::vec3 target);

	//! Set camera to work with perspective projection.

	/*!
	\param fov - specifies how much space camera will see.
	\param aspectRatio - specifies current aspect ratio of camera.
	\param nearPlane - speciies how close objects will start to be discarded.
	\param farPlane - specfies how far objects will start to be discarded.
	*/
	void Perspective(float fov, float aspectRatio, float nearPlane, float farPlane);

	//! Set camera to work with perspective projection.

	/*!
	\param left - specifies how much to the left of the screen camera will see.
	\param right - specifies how much to the right of the screen camera will see.
	\param top - specifies how much to the top of the screen camera will see.
	\param bottom - specifies how much to the bottom of the screen camera will see.
	\param near_plane - speciies how close objects will start to be discarded.
	\param far_plane - specfies how far objects will start to be discarded.
	*/
	void Orthographic(float left, float right, float top, float bottom, float near_plane, float far_plane);


	//! Transform of the camera.
	CTransform transform;

	//! Get projection matrix form the camera.

	/*!
	\return glm::mat4 holding all required information about currently used projection.
	*/
	glm::mat4 GetProjectionMatrix() { return projection; }

	//! Get current camera view matrix.
	glm::mat4 GetViewMat();
};