#include "TestGame.h"

#include <SGE_GameObject2D.h>

#include <iostream>

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
	//camera["main"]->transform.Position(glm::vec3(0, 1, 4));
	//camera["main"]->transform.Rotation(0, -90, 0);
	std::cout << "Look, I'm extending base class! :)" << std::endl;
	objects.push_back(new SGE_GameObject2D(STANDARD));
}

void TestGame::Update(GLfloat dt)
{

}

void TestGame::ProcessInput(GLfloat dt)
{

}

void TestGame::Render()
{
	glClearColor(0.14f, 0.2f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
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
		
		glfwPollEvents();
		this->ProcessInput(deltaTime);
		this->Update(deltaTime);
		this->Render();
	}
}
