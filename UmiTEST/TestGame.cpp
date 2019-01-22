#include "TestGame.h"

#include <VisualObject.h>

#include <iostream>

#include "Grass.h"
#include "StorageCrate.h"
#include <Plane.h>
#include <ResourceManager.h>
#include <DirectionalLight.h>
#include <LightManager.h>

#include <vector>
#include <algorithm>

#include "BuildingA.h"
#include "BuildingB.h"

TestGame::TestGame() : Game()
{
	camera["main"] = new Camera();
	color = 0.0f;
}

TestGame::~TestGame()
{
}

void TestGame::Init(GLuint screen_width, GLuint screen_height)
{
	Game::Init(screen_width, screen_height);

	ResourceManager::LoadTexture("assets/textures/grass/grass_terrain.jpg", "grass_terrain");

	ResourceManager::LoadTexture("assets/textures/storage_crate.png", "storage_crate");
	ResourceManager::LoadTexture("assets/textures/storage_crate_spec.png", "storage_crate_spec");

	std::vector<GLchar*> filenames;
	//filenames.push_back((GLchar*)"assets/textures/skybox/ocean/right.jpg");
	//filenames.push_back((GLchar*)"assets/textures/skybox/ocean/left.jpg");
	//filenames.push_back((GLchar*)"assets/textures/skybox/ocean/top.jpg");
	//filenames.push_back((GLchar*)"assets/textures/skybox/ocean/bottom.jpg");
	//filenames.push_back((GLchar*)"assets/textures/skybox/ocean/front.jpg");
	//filenames.push_back((GLchar*)"assets/textures/skybox/ocean/back.jpg");

	filenames.push_back((GLchar*)"assets/textures/skybox/clouds/right.png");
	filenames.push_back((GLchar*)"assets/textures/skybox/clouds/left.png");
	filenames.push_back((GLchar*)"assets/textures/skybox/clouds/top.png");
	filenames.push_back((GLchar*)"assets/textures/skybox/clouds/bottom.png");
	filenames.push_back((GLchar*)"assets/textures/skybox/clouds/front.png");
	filenames.push_back((GLchar*)"assets/textures/skybox/clouds/back.png");

	ResourceManager::LoadCubeMap(filenames, "skybox_ocean");

	//camera["main"]->Orthographic(0.0f, screen_width, 0.0f, screen_height, -1.0f, 1.0f);
	camera["main"]->Perspective(45.f, 16.f / 9.f, .01f, 1000.f);
	camera["main"]->transform.Position(glm::vec3(0.0f, 1.0f, 0.0f));
	camera["main"]->transform.Rotation(0, 0, 0);
	
	sky = new Skybox();
	sky->texture = ResourceManager::GetTexture("skybox_ocean");

	Plane* ground = new Plane();
	ground->material = Material::white;
	ground->material.specular = glm::vec3(0.0f, 0.0f, 0.0f);
	ground->material.diffuseTexture = ResourceManager::GetTexture("grass_terrain");
	ground->transform.Scale(100.0f, 1.0f, 100.0f);
	for (auto &uv : ground->meshes[0]->uvs)
	{
		uv *= 50;
	}
	ground->meshes[0]->RecalculateNormals();
	ground->meshes[0]->CreateMesh();
	ground->receiveShadows = true;
	objects.push_back(ground);
	opaque_objs.push_back(ground);

	StorageCrate* kostka = nullptr;
	int z = 0;
	kostka = new StorageCrate();
	z = rand() % 50 + 1;
	kostka->transform.Position(glm::vec3(5.0f, 1.0f + (z / 10) , 5.0f));
	kostka->setRotationDirection(glm::vec3(1, 0, -1));
	kostka->setRotationSpeed(10.0f);
	objects.push_back(kostka);
	opaque_objs.push_back(kostka);

	kostka = new StorageCrate();
	z = rand() % 50 + 1;
	kostka->transform.Position(glm::vec3(-5.0f, 1.0f + (z / 10), 5.0f));
	kostka->setRotationDirection(glm::vec3(1, 0, -1));
	kostka->setRotationSpeed(10.0f);
	objects.push_back(kostka);
	opaque_objs.push_back(kostka);

	kostka = new StorageCrate();
	z = rand() % 50 + 1;
	kostka->transform.Position(glm::vec3(5.0f, 1.0f + (z / 10), -5.0f));
	kostka->setRotationDirection(glm::vec3(1, 0, -1));
	kostka->setRotationSpeed(10.0f);
	objects.push_back(kostka);
	opaque_objs.push_back(kostka);

	kostka = new StorageCrate();
	z = rand() % 50 + 1;
	kostka->transform.Position(glm::vec3(-5.0f, 1.0f + (z / 10), -5.0f));
	kostka->setRotationDirection(glm::vec3(1, 0, -1));
	kostka->setRotationSpeed(10.0f);
	objects.push_back(kostka);
	opaque_objs.push_back(kostka);


	Grass* tGrass = nullptr;
	for (int i = 0; i < 100; i++)
	{
		int x = rand() % 101 - 50;
		int y = rand() % 101 - 50;
		tGrass = new Grass();
		tGrass->transform.Position(glm::vec3(x, 0.0f, y));
		transparent_objs.push_back(tGrass);
		this->objects.push_back(tGrass);
	}

	BuildingA* tBuild = new BuildingA();
	tBuild->transform.Position(glm::vec3(5.0f, 0.0f, 10.0f));
	objects.push_back(tBuild);
	opaque_objs.push_back(tBuild);

	BuildingB* tBuild2 = new BuildingB();
	tBuild2->transform.Position(glm::vec3(25.0f, 0.0f, 2.0f));
	tBuild2->transform.Rotation(glm::vec3(0.0f, -90.0f, 0.0f));
	objects.push_back(tBuild2);
	opaque_objs.push_back(tBuild2);


	DirectionalLight* tLight = new DirectionalLight();
	tLight->direction = glm::vec3(-0.5f, -1.0f, 1.5f);
	tLight->diffuse = glm::vec3(0.85f, 0.85f, 0.8f);
	tLight->ambient = glm::vec3(0.7f,0.7f,0.7f);
	tLight->specular = glm::vec3(1.0f, 1.0f, 1.0f);

	LightManager::AddDirectionalLight(tLight);

	
}

bool TestGame::testCompare(glm::vec3 lhs, glm::vec3 rhs)
{
	return glm::distance(lhs, this->camera["main"]->transform.Position()) < glm::distance(rhs, this->camera["main"]->transform.Position());
}

void TestGame::Update(GLfloat dt)
{
	camera["main"]->Update(dt);
	for (auto &object : objects)
	{
		object->Update(dt);
	}
}

void TestGame::MainLoop()
{	
	GLfloat deltaTime = 0.0f;
	GLfloat lastFrame = 0.0f;
	while (!glfwWindowShouldClose(this->window))
	{
		// Calculate delta time
		GLfloat currentFrame = (GLfloat)glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		std::cout << "FPS: " << 1.0f / deltaTime << std::endl;

		this->ProcessInput(deltaTime);
		this->Update(deltaTime);
		this->Render();

		glfwPollEvents();
	}
}
