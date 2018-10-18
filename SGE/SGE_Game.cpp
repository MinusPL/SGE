#include "SGE_Game.h"
#include "SGE_ResourceManager.h"
#include "SGE_SpriteRenderer.h"

SGE_SpriteRenderer* Renderer;

SGE_Game::SGE_Game(GLuint width, GLuint height) 
	: State(GAME_ACTIVE), Keys(), Width(width), Height(height)
{
}

SGE_Game::~SGE_Game()
{
	delete Renderer;
}

void SGE_Game::Init()
{
	//Load shader
	SGE_ResourceManager::LoadShader("assets/shader/sprite.vs", "assets/shader/sprite.frag", nullptr, "Sprite");
	//Setup shader
	glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(this->Width), static_cast<GLfloat>(this->Height), 0.0f, -1.0f, 1.0f);
	SGE_ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
	SGE_ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);
	// Load textures
	SGE_ResourceManager::LoadTexture("assets/texture/player/player.png", GL_TRUE, "Player");
	// Set render-specific controls
	Renderer = new SGE_SpriteRenderer(SGE_ResourceManager::GetShader("Sprite"));

}

void SGE_Game::ProcessInput(GLfloat dt)
{
}

void SGE_Game::Update(GLfloat dt)
{
}

void SGE_Game::Render()
{
	Renderer->DrawSprite(SGE_ResourceManager::GetTexture("Player"), glm::vec2(0, 0), glm::vec2(128, 192), 0.0f, glm::vec3(1.0f, 1.0f, 1.0f));
}
