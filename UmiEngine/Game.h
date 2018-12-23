#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include <IL/ilut.h>
#include <GLFW/glfw3.h>

#include <map>
#include <string>
#include <vector>

#include "Camera.h"
#include "GameObject.h"

class Game
{
public:
	
	static Game* instance;

	Game();
	~Game();

	void Init(GLuint screen_width, GLuint screen_height);

	//Update logic
	virtual void Update(GLfloat dt) = 0;

	//Handle input
	void ProcessInput(GLfloat dt);
	
	//Render
	virtual void Render() = 0;

	//Main game loop
	virtual void MainLoop() = 0;

	//Cleanup and exit code
	void Exit();

	std::map<std::string,Camera*> camera;
	std::vector<GameObject*> objects;
	std::vector<GameObject*> transparent_objs;
	std::vector<GameObject*> opaque_objs;
protected:
	GLFWwindow* window;
};