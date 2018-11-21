#include "TestGame.h"

#include <VisualObject.h>

#include <iostream>

#include "Player.h"
#include <Cube.h>
#include <Plane.h>
#include <ResourceManager.h>

TestGame::TestGame()
{
	camera["main"] = new Camera();
	color = 0.0f;
}

TestGame::~TestGame()
{
}

void TestGame::Init(GLuint screen_width, GLuint screen_height)
{
	Game::Init(screen_width, screen_height);

	ResourceManager::LoadTexture("assets/textures/umi.png", "umi");
	ResourceManager::LoadTexture("assets/textures/spec_umi.png", "spec_umi");
	ResourceManager::LoadTexture("assets/textures/normal_umi.png", "normal_umi");

	//camera["main"]->Orthographic(0.0f, screen_width, 0.0f, screen_height, -1.0f, 1.0f);
	camera["main"]->Perspective(45.f, 16.f / 9.f, .01f, 1000.f);
	camera["main"]->transform.Position(glm::vec3(0.0f, 1.0f, 3.0f));
	camera["main"]->transform.Rotation(-20, 0, 0);
	//std::cout << "Look, I'm extending base class! :)" << std::endl;
	Player* tPlayer = new Player();
	objects.push_back(tPlayer);
	objects[0]->transform.Position(glm::vec3(10, 0, 0));
	objects[0]->transform.Rotation(glm::vec3(0, -90, 0));

	Cube* kostka = new Cube();
	kostka->material = Material::white;
	kostka->material.diffuseTexture = &ResourceManager::GetTexture("umi");
	kostka->material.specularTexture = &ResourceManager::GetTexture("spec_umi");
	kostka->material.normalMap = &ResourceManager::GetTexture("normal_umi");
	objects.push_back(kostka);
	objects[1]->transform.Position(glm::vec3(3, 0, 5));
	objects[1]->transform.Rotation(glm::vec3(0, 0, 0));

	Plane* ground = new Plane();
	ground->material = Material::chrome;
	ground->transform.Scale(100.0f, 0.0f, 100.0f);
	objects.push_back(ground);
}

void TestGame::Update(GLfloat dt)
{
	camera["main"]->Update(dt);
	for (auto &object : objects)
	{
		object->Update(dt);
	}
}

//void TestGame::ProcessInput(GLfloat dt)
//{
//
//	if (glfwGetKey(this->window, GLFW_KEY_F10) == GLFW_PRESS)
//	{
//		ILuint imagename;
//		ilGenImages(1, &imagename);
//		ilBindImage(imagename);
//		ilutGLScreen();
//		ilSaveImage("screen.png");
//		ilDeleteImages(1, &imagename);
//	}
//
//
//}

void TestGame::Render()
{
	glClearColor(0.14f, 0.2f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	for (unsigned int i = 0; i < objects.size(); i++)
	{
		objects[i]->Draw();
	}

	glfwSwapBuffers(this->window);
}

void TestGame::MainLoop()
{	
	GLfloat deltaTime = 0.0f;
	GLfloat lastFrame = 0.0f;
	while (!glfwWindowShouldClose(this->window))
	{
		// Calculate delta time
		GLfloat currentFrame = (GLfloat)glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		
		//std::cout << "Delta Time: " << deltaTime << std::endl;

		this->ProcessInput(deltaTime);
		this->Update(deltaTime);
		this->Render();

		glfwPollEvents();
	}
}
