#include "Player.h"
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <Input.h>


Player::Player() : VisualObject((GLchar*)"assets/models/kotori.fbx", STANDARD_SHADELESS)
{
}

Player::~Player()
{
	
}


void Player::Update(GLfloat dt)
{
	float speed = 2.0f;
	float rot_speed = 20.0f;
	
	if (Input::GetKey(Key::KEY_R))
	{
		this->transform.Rotation(this->transform.Rotation() + glm::vec3(0.0f, 0.0f, rot_speed * dt));
	}
	if (Input::GetKey(Key::KEY_F))
	{
		this->transform.Rotation(this->transform.Rotation() + glm::vec3(0.0f, 0.0f, -rot_speed * dt));
	}
	
	if (Input::GetKey(Key::KEY_T))
	{
		this->transform.Rotation(this->transform.Rotation() + glm::vec3(0.0f, rot_speed * dt, 0.0f));
	}
	if (Input::GetKey(Key::KEY_G))
	{
		this->transform.Rotation(this->transform.Rotation() + glm::vec3(0.0f, -rot_speed * dt, 0.0f));
	}
	
	if (Input::GetKey(Key::KEY_Y))
	{
		this->transform.Rotation(this->transform.Rotation() + glm::vec3(rot_speed * dt, 0.0f, 0.0f));
	}
	if (Input::GetKey(Key::KEY_H))
	{
		this->transform.Rotation(this->transform.Rotation() + glm::vec3(-rot_speed * dt, 0.0f, 0.0f));
	}
}
