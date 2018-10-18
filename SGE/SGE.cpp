#define GLEW_STATIC
#include <gl/glew.h>
#include <GLFW/glfw3.h>

#include "SGE_Game.h"
#include "SGE_ResourceManager.h"

GLuint ScreenWidth = 1280;
GLuint ScreenHeight = 720;

SGE_Game SGE(ScreenWidth, ScreenHeight);

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

int main(int argc, char* args[])
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(ScreenWidth, ScreenHeight, "NO-NAME", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	glewInit();
	glGetError(); // Call it once to catch glewInit() bug, all other errors are now from our application.

	glfwSetKeyCallback(window, key_callback);

	// OpenGL configuration
	glViewport(0, 0, 1280, 720);
	glEnable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	SGE.Init();

	GLfloat deltaTime = 0.0f;
	GLfloat lastFrame = 0.0f;

	while (!glfwWindowShouldClose(window))
	{
		GLfloat currentFrame = (float)glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		glfwPollEvents();
		//LOGIC
		SGE.Update(deltaTime);
		//END
		//RENDER
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		SGE.Render();
		//END
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	// When a user presses the escape key, we set the WindowShouldClose property to true, closing the application
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
			SGE.Keys[key] = GL_TRUE;
		else if (action == GLFW_RELEASE)
			SGE.Keys[key] = GL_FALSE;
	}
}