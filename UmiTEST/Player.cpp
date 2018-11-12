#include "Player.h"
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>



Player::Player() : VisualObject((GLchar*)"assets/models/kotori.fbx", STANDARD)
{
}

Player::~Player()
{
	
}


void Player::Update(GLfloat dt)
{
	//this->transform.Rotation(this->transform.Rotation() + glm::vec3(0.0f, 0.0f, 0.05f));
}
