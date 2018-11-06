#include "Player.h"
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>



Player::Player() : SGE_GameObject2D(STANDARD)
{
	glm::vec3 size(128.0f, 192.0f, 0.0f);
	for (auto &vertex : this->mesh.vertices)
	{
		vertex = vertex * size;
	}
	this->mesh.CreateMesh();
	//this->transform.Scale(glm::vec3(2.0f, 2.0f, 1.0f));
}

Player::~Player()
{
}

void Player::LoadTexture(std::string filename)
{

}

void Player::Update()
{

}
