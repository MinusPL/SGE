#include "StorageCrate.h"
#include <ResourceManager.h>

StorageCrate::StorageCrate() : Cube()
{
	this->material = Material::white;
	this->material.diffuseTexture = ResourceManager::GetTexture("storage_crate");
	this->material.specularTexture = ResourceManager::GetTexture("storage_crate_spec");
}

void StorageCrate::Update(GLfloat dt)
{
	this->transform.Rotation(this->transform.Rotation() + (this->rotationDirection * rotSpeed * dt));
}

void StorageCrate::setRotationDirection(glm::vec3 rotTemplate)
{
	this->rotationDirection = rotTemplate;
}

void StorageCrate::setRotationSpeed(float speed)
{
	this->rotSpeed = speed;
}
