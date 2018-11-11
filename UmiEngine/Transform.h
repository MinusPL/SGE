#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Transform
{
	glm::vec3 forward;
	glm::vec3 right;
	glm::vec3 up;
	
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;

	void UpdateVectors();

public:

	Transform* parent = nullptr;

	//void LookAt(glm::vec3 target);

	glm::vec3 Forward() { return forward; }
	glm::vec3 Right() { return right; }
	glm::vec3 Up() { return up; }

	glm::vec3 Position() { return position; }
	void Position(glm::vec3 newPos) {
		position = newPos;
		UpdateVectors();
	}
	void Position(float x, float y, float z) {
		position = glm::vec3(x, y, z);
		UpdateVectors();
	}

	glm::vec3 Rotation() { return rotation; }
	void Rotation(glm::vec3 newRot) {
		rotation = newRot;
		UpdateVectors();
	}
	void Rotation(float x, float y, float z) {
		rotation = glm::vec3(x, y, z);
		UpdateVectors();
	}

	glm::vec3 Scale() { return scale; }
	void Scale(glm::vec3 newScale) { scale = newScale; }
	void Scale(float x, float y, float z) {
		scale = glm::vec3(x, y, z);
	}

	glm::mat4 ApplyTransform();
	glm::vec3 WorldPosition();

	Transform();
	~Transform();
};