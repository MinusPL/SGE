#include "VisualObject.h"
#include "ResourceManager.h"
#include "Game.h"

void VisualObject::Draw()
{
	this->shader.Use();

	glm::mat4 model = transform.ApplyTransform();
	glm::mat4 MVP = Game::instance->camera["main"]->GetProjectionMatrix() * Game::instance->camera["main"]->GetViewMat() * model;
	glm::mat3 normalModel = (glm::mat3) glm::transpose(glm::inverse(model));

	this->shader.SetMatrix4("MVP", MVP);
	this->shader.SetMatrix4("model", model);
	this->shader.SetVector3f("viewPos", Game::instance->camera["main"]->transform.Position());

	this->shader.SetVector3f("dirLight.direction", 0.7f, -0.4f, 0.2f);
	
	float ambientval = 0.7f;
	this->shader.SetVector3f("dirLight.ambient", ambientval, ambientval, ambientval);
	this->shader.SetVector3f("dirLight.diffuse", 0.8f,0.8f,0.8f);
	this->shader.SetVector3f("dirLight.specular", 1.0f,1.0f,1.0f);

	this->shader.SetMatrix3("normalModel", normalModel);

	this->model.Draw(&this->shader);
}

VisualObject::VisualObject(GLchar* model_file, ShaderType shaderType) : model(model_file)
{
	switch (shaderType)
	{
		case STANDARD:
		{
			this->shader = ResourceManager::GetShader("standard");
			break;
		}
	}
}

VisualObject::~VisualObject()
{

}
