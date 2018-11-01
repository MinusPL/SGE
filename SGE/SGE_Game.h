#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <map>
#include <string>
#include <vector>

#include "SGE_Camera.h"
#include "SGE_GameObject.h"

class SGE_Game
{
public:
	
	static SGE_Game* instance;

	SGE_Game();
	~SGE_Game();

	void Init(GLuint screen_width, GLuint screen_height);

	//Update logic
	virtual void Update(GLfloat dt) = 0;

	//Handle input
	virtual void ProcessInput(GLfloat dt) = 0;
	
	//Render
	virtual void Render() = 0;

	//Main game loop
	virtual void MainLoop() = 0;

	//Cleanup and exit code
	void Exit();

	std::map<std::string,SGE_Camera*> camera;
	std::vector<SGE_GameObject*> objects;
protected:
	GLFWwindow* window;
};