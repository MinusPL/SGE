#pragma once
#include <IL/il.h>

#include <VisualObject.h>

class Player : public VisualObject
{
public:
	Player();
	~Player();
	void LoadTexture(std::string filename);
	// Inherited via SGE_GameObject2D
	virtual void Update(GLfloat dt) override;
private:
	ILuint texture;
};