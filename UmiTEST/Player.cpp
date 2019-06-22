#include "Player.h"
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <Input.h>
#include <ResourceManager.h>
#include <Game.h>


Player::Player() : VisualObject((GLchar*)"assets/models/player/kotori.fbx", STANDARD_SHADELESS)
{

}

Player::~Player()
{
	
}

void Player::Update(GLfloat dt)
{
	float speed = 4.0f;
	float rot_speed = 35.0f;

	if (Input::GetKey(Key::KEY_LEFT_SHIFT))
	{
		speed = 10.0f;
	}
	else
	{
		speed = 4.0f;
	}

	if (Input::GetKey(Key::KEY_UP))
	{
		this->transform.Position(this->transform.Position() + (this->transform.Forward() * speed * dt));
	}

	if (Input::GetKey(Key::KEY_DOWN))
	{
		this->transform.Position(this->transform.Position() + (this->transform.Forward() * -speed * dt));
	}
	
	if (Input::GetKey(Key::KEY_LEFT))
	{
		this->transform.Rotation(this->transform.Rotation() + glm::vec3(0.0f, rot_speed * dt, 0.0f));
	}

	if (Input::GetKey(Key::KEY_RIGHT))
	{
		this->transform.Rotation(this->transform.Rotation() + glm::vec3(0.0f, -rot_speed * dt, 0.0f));
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
	//Game::instance->camera["main"]->transform.Position(this->transform.Position() + glm::vec3(0.0f, 2.0f, 0.0f));
	//Game::instance->camera["main"]->transform.Rotation(this->transform.Rotation());
}
