#include "SGE_GameObject2D.h"
#include "SGE_ResourceManager.h"
#include "SGE_Game.h"

void SGE_GameObject2D::Draw()
{
	this->shader.Use();

	glm::mat4 model = transform.ApplyTransform();
	glm::mat4 MVP = SGE_Game::instance->camera["main"]->GetProjectionMatrix() * SGE_Game::instance->camera["main"]->GetViewMat() * model;
	glm::mat3 normalModel = (glm::mat3) glm::transpose(glm::inverse(model));


	this->shader.SetMatrix4("MVP", MVP);
	this->shader.SetMatrix4("model", model);
	this->shader.SetVector3f("viewPos", SGE_Game::instance->camera["main"]->transform.Position());

	mesh.Draw();
}

void SGE_GameObject2D::Update()
{
}

SGE_GameObject2D::SGE_GameObject2D(ShaderType shaderType)
{
	switch (shaderType)
	{
		case STANDARD:
		{
			this->shader = SGE_ResourceManager::GetShader("standard");
			break;
		}
	}
	mesh.vertices.push_back(glm::vec3(0.5f, 0.5f, 0.0f));	// TOP RIGHT
	mesh.vertices.push_back(glm::vec3(0.5f, -0.5f, 0.0f));	// BOTTOM RIGHT
	mesh.vertices.push_back(glm::vec3(-0.5f, -0.5f, 0.0f));	// BOTTOM LEFT
	mesh.vertices.push_back(glm::vec3(-0.5f, 0.5f, 0.0f));	// TOP LEFT

	mesh.indices.push_back(0);
	mesh.indices.push_back(1);
	mesh.indices.push_back(2);
	mesh.indices.push_back(0);
	mesh.indices.push_back(3);
	mesh.indices.push_back(2);

	mesh.uvs.push_back(glm::vec2(1, 1));
	mesh.uvs.push_back(glm::vec2(1, 0));
	mesh.uvs.push_back(glm::vec2(0, 0));
	mesh.uvs.push_back(glm::vec2(0, 1));

	mesh.RecalculateNormals();
	mesh.CreateMesh();
}

SGE_GameObject2D::~SGE_GameObject2D()
{

}
