#include "Game.h"
#include "ResourceManager.h"
#include "Input.h"

Game* Game::instance = nullptr;

Game::Game()
{
}

Game::~Game()
{
}

void Game::Init(GLuint screen_width, GLuint screen_height)
{
	if (instance != nullptr)
	{
		throw "Multiple instances of game";
	}
	instance = this;
	
	if ((ilGetInteger(IL_VERSION_NUM) < IL_VERSION) ||
		ilGetInteger(ILUT_VERSION_NUM) < ILUT_VERSION)
	{
		printf("DevIL version is different...exiting!\n");
	}

	ilInit();
	iluInit();
	ilutInit();

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	window = glfwCreateWindow(screen_width, screen_height, "SGE Engine v0.0.1", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	ilutRenderer(ILUT_OPENGL);
	glewExperimental = GL_TRUE;
	glewInit();


	glViewport(0, 0, screen_width, screen_height);
	//glEnable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_STENCIL_TEST);
	glEnable(GL_TEXTURE_2D);


	Input::GetInstance();
	ResourceManager::LoadShader("standard.vs", "standard.fs", nullptr, "standard");
}

void Game::ProcessInput(GLfloat dt)
{
	Input::previousState = Input::keyState;
	for (auto &key : Input::keyState)
	{
		key.second = glfwGetKey(this->window, (int)key.first) == GLFW_PRESS ? true : false;
	}
}

void Game::Exit()
{
	glfwTerminate();
}