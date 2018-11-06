#include "TestGame.h"

#include <SGE_GameObject2D.h>

#include <iostream>

#include "Player.h"

TestGame::TestGame()
{
	camera["main"] = new SGE_Camera(MODE_2D);
	color = 0.0f;
}

TestGame::~TestGame()
{
}

void TestGame::Init(GLuint screen_width, GLuint screen_height)
{
	SGE_Game::Init(screen_width, screen_height);
	camera["main"]->Orthographic(0.0f, screen_width, 0.0f, screen_height, -1.0f, 1.0f);
	//camera["main"]->Perspective(45.f, 16.f / 9.f, .01, 1000.f);
	camera["main"]->transform.Position(glm::vec3(0.0f, 0.0f, 0.0f));
	camera["main"]->transform.Rotation(0, -90, 0);
	//std::cout << "Look, I'm extending base class! :)" << std::endl;
	objects.push_back(new Player());
	objects[0]->transform.Position(glm::vec3(640.0f, 360.0f, 0));
	objects[0]->transform.Rotation(glm::vec3(0, 0, 0));
}

void TestGame::Update(GLfloat dt)
{

}

void TestGame::ProcessInput(GLfloat dt)
{
	if (glfwGetKey(this->window, GLFW_KEY_W) == GLFW_PRESS)
	{
		objects[0]->transform.Position(objects[0]->transform.Position() + glm::vec3(0.0f, -200.0f * dt, 0.0f));
		if (objects[0]->transform.Position().y - 96.0f < 0.0f) objects[0]->transform.Position(glm::vec3(objects[0]->transform.Position().x, 96.0f, 0.0f));
	}
	if (glfwGetKey(this->window, GLFW_KEY_S) == GLFW_PRESS)
	{
		objects[0]->transform.Position(objects[0]->transform.Position() + glm::vec3(0.0f, 200.0f * dt, 0.0f));
		if (objects[0]->transform.Position().y + 96.0f > 720) objects[0]->transform.Position(glm::vec3(objects[0]->transform.Position().x, 720.0f - 96.0f, 0.0f));
	}
	if (glfwGetKey(this->window, GLFW_KEY_A) == GLFW_PRESS)
	{
		objects[0]->transform.Position(objects[0]->transform.Position() + glm::vec3(-200.0f * dt, 0.0f, 0.0f));
		if (objects[0]->transform.Position().x - 64.0f < 0) objects[0]->transform.Position(glm::vec3(64.0f, objects[0]->transform.Position().y, 0.0f));
	}
	if (glfwGetKey(this->window, GLFW_KEY_D) == GLFW_PRESS)
	{
		objects[0]->transform.Position(objects[0]->transform.Position() + glm::vec3(200.0f * dt, 0.0f, 0.0f));
		if (objects[0]->transform.Position().x + 64.0f > 1280.0f) objects[0]->transform.Position(glm::vec3(1280.0f - 64.0f, objects[0]->transform.Position().y, 0.0f));
	}
}

void TestGame::Render()
{
	glClearColor(0.14f, 0.2f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Insert render functions here later

	for (int i = 0; i < objects.size(); i++)
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
		GLfloat currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		
		//std::cout << "Delta Time: " << deltaTime << std::endl;

		this->ProcessInput(deltaTime);
		this->Update(deltaTime);
		this->Render();

		glfwPollEvents();
	}
}
