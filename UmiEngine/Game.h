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
#include "Skybox.h"


//! Main Game class

/*!
Main game class that is extended in an implementation.
It has all base methods and fields required to work.
It also has all vectors that hold all game objects.
*/
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
	void Render();

	//Main game loop
	virtual void MainLoop() = 0;

	//Cleanup and exit code
	void Exit();

	std::map<std::string, Camera*> camera;
	std::vector<GameObject*> objects;
	std::vector<GameObject*> transparent_objs;
	std::vector<GameObject*> opaque_objs;
protected:
	GLFWwindow* window;
	Skybox* sky;
	unsigned int screenVAO, screenVBO;
	unsigned int fbo, tbo, rbo;
	unsigned int depthMapFBO, depthMap;
	unsigned int hdrFBO, colorBuffers[2];
	unsigned int pingpongFBO[2], pingpongColorbuffers[2];
	const int SHADOW_WIDTH = 2048, SHADOW_HEIGHT = 2048;
	int screen_width = 1280, screen_height = 720;
};