#include "SGE_Game.h"
#include "SGE_ResourceManager.h"

SGE_Game* SGE_Game::instance = nullptr;

SGE_Game::SGE_Game()
{
}

SGE_Game::~SGE_Game()
{
}

void SGE_Game::Init(GLuint screen_width, GLuint screen_height)
{
	if (instance != nullptr)
	{
		throw "Multiple instances of game";
	}
	instance = this;
	
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	window = glfwCreateWindow(screen_width, screen_height, "SGE Engine v0.0.1", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;
	glewInit();

	//glfwSetKeyCallback(window, key_callback);
	glViewport(0, 0, screen_width, screen_height);
	glEnable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);

	SGE_ResourceManager::LoadShader("standard.vs", "standard.fs", nullptr, "standard");
}

void SGE_Game::Exit()
{
	glfwTerminate();
}