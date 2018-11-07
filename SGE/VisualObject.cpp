#include "VisualObject.h"
#include "ResourceManager.h"
#include "Game.h"

void VisualObject::Draw()
{
	this->shader.Use();

	glm::mat4 model = transform.ApplyTransform();
	glm::mat4 MVP = Game::instance->camera["main"]->GetProjectionMatrix() * Game::instance->camera["main"]->GetViewMat() * model;
	
	
	//glm::mat3 normalModel = (glm::mat3) glm::transpose(glm::inverse(model));


	this->shader.SetMatrix4("MVP", MVP);
	this->shader.SetMatrix4("model", model);
	this->shader.SetVector3f("viewPos", Game::instance->camera["main"]->transform.Position());

	//Pass material to shader
	this->shader.SetVector3f("material.ambient", this->material.ambient);
	this->shader.SetVector3f("material.diffuse", this->material.diffuse);
	this->shader.SetVector3f("material.specular", this->material.specular);
	this->shader.SetFloat("material.shiness", this->material.shiness);

	//TODO Change to pass lightning to shader properly
	this->shader.SetVector3f("dirLight.direction", glm::vec3(0.0f, 100.0f, 8.0f));
	this->shader.SetVector3f("dirLight.ambient",1.0f,1.0f,1.0f);
	this->shader.SetVector3f("dirLight.diffuse", 1.0f, 1.0f, 1.0f);
	this->shader.SetVector3f("dirLight.specular", 1.0f, 1.0f, 1.0f);;

	mesh.Draw();
}

VisualObject::VisualObject(ShaderType shaderType)
{
	switch (shaderType)
	{
		case STANDARD:
		{
			this->shader = ResourceManager::GetShader("standard");
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
	mesh.indices.push_back(2);
	mesh.indices.push_back(3);

	mesh.uvs.push_back(glm::vec2(1, 1));
	mesh.uvs.push_back(glm::vec2(1, 0));
	mesh.uvs.push_back(glm::vec2(0, 0));
	mesh.uvs.push_back(glm::vec2(0, 1));

	mesh.RecalculateNormals();
	mesh.CreateMesh();
}

VisualObject::~VisualObject()
{

}
