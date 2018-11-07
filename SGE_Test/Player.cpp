#include "Player.h"
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>



Player::Player() : VisualObject(STANDARD)
{
	glm::vec3 size(128.0f, 192.0f, 0.0f);
	for (auto &vertex : this->mesh.vertices)
	{
		vertex = vertex * size;
	}
	this->mesh.CreateMesh();
	this->material = Material::gold;
}

Player::~Player()
{
	
}

void Player::LoadTexture(std::string filename)
{

}

void Player::Update(GLfloat dt)
{
	//this->transform.Rotation(this->transform.Rotation() + glm::vec3(0.0f, 0.5f, 0.0f));
}
