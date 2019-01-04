#pragma once

#include <Game.h>
#include <gl/glew.h>
#include <Skybox.h>

class TestGame : public Game
{
public:
	TestGame();
	~TestGame();
	void Init(GLuint screen_width, GLuint screen_height);
	// Inherited via SGE_Game
	virtual void Update(GLfloat dt) override;
	virtual void MainLoop() override;

	bool testCompare(glm::vec3 lhs, glm::vec3 rhs);
private:
	GLfloat color;
};