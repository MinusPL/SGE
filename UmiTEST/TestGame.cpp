#include "TestGame.h"

#include <VisualObject.h>

#include <iostream>

#include "Player.h"
#include "Grass.h"
#include <Cube.h>
#include <Plane.h>
#include <ResourceManager.h>

#include <vector>
#include <algorithm>

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

	std::vector<GLchar*> filenames;
	filenames.push_back((GLchar*)"assets/textures/skybox/ocean/right.jpg");
	filenames.push_back((GLchar*)"assets/textures/skybox/ocean/left.jpg");
	filenames.push_back((GLchar*)"assets/textures/skybox/ocean/top.jpg");
	filenames.push_back((GLchar*)"assets/textures/skybox/ocean/bottom.jpg");
	filenames.push_back((GLchar*)"assets/textures/skybox/ocean/front.jpg");
	filenames.push_back((GLchar*)"assets/textures/skybox/ocean/back.jpg");

	//filenames.push_back((GLchar*)"assets/textures/tex8.png");
	//filenames.push_back((GLchar*)"assets/textures/tex8.png");
	//filenames.push_back((GLchar*)"assets/textures/tex8.png");
	//filenames.push_back((GLchar*)"assets/textures/tex8.png");
	//filenames.push_back((GLchar*)"assets/textures/tex8.png");
	//filenames.push_back((GLchar*)"assets/textures/tex8.png");

	ResourceManager::LoadCubeMap(filenames, "skybox_ocean");

	//camera["main"]->Orthographic(0.0f, screen_width, 0.0f, screen_height, -1.0f, 1.0f);
	camera["main"]->Perspective(45.f, 16.f / 9.f, .01f, 1000.f);
	camera["main"]->transform.Position(glm::vec3(0.0f, 1.0f, 3.0f));
	camera["main"]->transform.Rotation(-20, 0, 0);
	//std::cout << "Look, I'm extending base class! :)" << std::endl;
	
	sky = new Skybox();
	sky->texture = ResourceManager::GetTexture("skybox_ocean");
	
	Player* tPlayer = new Player();
	tPlayer->transform.Position(glm::vec3(10, 0, 0));
	tPlayer->transform.Rotation(glm::vec3(0, -90, 0));
	objects.push_back(tPlayer);
	opaque_objs.push_back(tPlayer);


	tPlayer = new Player();
	tPlayer->transform.Position(glm::vec3(-10, 0, 0));
	tPlayer->transform.Rotation(glm::vec3(0, -90, 0));
	objects.push_back(tPlayer);
	opaque_objs.push_back(tPlayer);

	Cube* kostka = new Cube();
	kostka->material = Material::white;
	kostka->material.diffuseTexture = ResourceManager::GetTexture("umi");
	kostka->material.specularTexture = ResourceManager::GetTexture("spec_umi");
	kostka->material.normalMap = ResourceManager::GetTexture("normal_umi");
	kostka->transform.Position(glm::vec3(3, 0, 5));
	kostka->transform.Rotation(glm::vec3(0, 0, 0));
	objects.push_back(kostka);
	opaque_objs.push_back(kostka);


	Plane* ground = new Plane();
	ground->material = Material::chrome;
	ground->transform.Scale(100.0f, 0.0f, 100.0f);
	objects.push_back(ground);
	opaque_objs.push_back(ground);


	Grass* tGrass = nullptr;
	for (int i = 0; i < 100; i++)
	{
		int x = rand() % 101 - 50;
		int y = rand() % 101 - 50;
		tGrass = new Grass();
		tGrass->transform.Position(glm::vec3(x, 0.0f, y));
		transparent_objs.push_back(tGrass);
	}

}

bool TestGame::testCompare(glm::vec3 lhs, glm::vec3 rhs)
{
	return glm::distance(lhs, this->camera["main"]->transform.Position()) < glm::distance(rhs, this->camera["main"]->transform.Position());
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

	sky->Draw();

	for (auto &object : opaque_objs)
	{
		object->Draw();
	}

	glDisable(GL_CULL_FACE);

	glDepthMask(GL_FALSE);

	std::map<float, GameObject*> sorted;
	for (auto &object : transparent_objs)
	{
		float distance = glm::length(this->camera["main"]->transform.Position() - object->transform.Position());
		sorted[distance] = object;
	}

	for (std::map<float, GameObject*>::reverse_iterator it = sorted.rbegin(); it != sorted.rend(); ++it)
	{
		it->second->Draw();
	}

	glDepthMask(GL_TRUE);

	glEnable(GL_CULL_FACE);

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
		
		std::cout << "Delta Time: " << deltaTime << std::endl;

		this->ProcessInput(deltaTime);
		this->Update(deltaTime);
		this->Render();

		glfwPollEvents();
	}
}
