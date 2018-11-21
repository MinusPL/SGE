#include "Player.h"
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <Input.h>


Player::Player() : VisualObject((GLchar*)"assets/models/kotori.fbx", STANDARD)
{
}

Player::~Player()
{
	
}


void Player::Update(GLfloat dt)
{
	float speed = 2.0f;
	float rot_speed = 20.0f;
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
