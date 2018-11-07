#pragma once

#include <glm/glm.hpp>

struct Material
{
	//Change to own Texture format after creating Texture Class
	/*sf::Texture* diffuseTexture = nullptr;
	sf::Texture* specularTexture = nullptr;
	sf::Texture* normalMap = nullptr;*/

	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;

	float shiness = 32;

#pragma region static materials
	static Material emerald;
	static Material jade;
	static Material obsidian;
	static Material pearl;
	static Material ruby;
	static Material turquoise;
	static Material brass;
	static Material bronze;
	static Material chrome;
	static Material copper;
	static Material gold;
	static Material silver;
	static Material blackPlastic;
	static Material cyanPlastic;
	static Material greenPlastic;
	static Material redPlastic;
	static Material whitePlastic;
	static Material yellowPlastic;
	static Material blackRubber;
	static Material cyanRubber;
	static Material greenRubber;
	static Material redRubber;
	static Material whiteRubber;
	static Material yellowRubber;
	static Material white;
#pragma endregion

	Material(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float shiness) {
		this->ambient = ambient;
		this->diffuse = diffuse;
		this->specular = specular;
		this->shiness = shiness;
	}

	Material() {};
};
