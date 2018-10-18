#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

enum GameState
{
	GAME_ACTIVE,
	GAME_MENU
};

class SGE_Game
{
public:
	GameState State;
	GLboolean Keys[1024];
	GLuint Width, Height;
	//class constructor&destructor
	SGE_Game(GLuint width, GLuint height);
	~SGE_Game();
	//Initialization
	void Init();
	//Game logic
	void ProcessInput(GLfloat dt);
	void Update(GLfloat dt);
	void Render();
};