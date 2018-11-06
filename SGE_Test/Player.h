#pragma once
#include <IL/il.h>

#include <SGE_GameObject2D.h>

class Player : public SGE_GameObject2D
{
public:
	Player();
	~Player();
	void LoadTexture(std::string filename);
	// Inherited via SGE_GameObject2D
	virtual void Update() override;
private:
	ILuint texture;
};