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

#include "Player.h"
#include "Bucket.h"
#include "Water.h"

StorageCrate* NormKostka = nullptr;

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

	ResourceManager::LoadTexture("assets/textures/test_crate.png", "storage_crate");
	ResourceManager::LoadTexture("assets/textures/storage_crate_spec.png", "storage_crate_spec");
	ResourceManager::LoadTexture("assets/textures/player_crate.png", "player_crate");
	ResourceManager::LoadTexture("assets/texture/umi_box.png", "umi_box");

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

	//filenames.push_back((GLchar*)"assets/textures/skybox/debug/right.jpg");
	//filenames.push_back((GLchar*)"assets/textures/skybox/debug/left.jpg");
	//filenames.push_back((GLchar*)"assets/textures/skybox/debug/top.jpg");
	//filenames.push_back((GLchar*)"assets/textures/skybox/debug/bottom.jpg");
	//filenames.push_back((GLchar*)"assets/textures/skybox/debug/front.jpg");
	//filenames.push_back((GLchar*)"assets/textures/skybox/debug/back.jpg");

	ResourceManager::LoadCubeMap(filenames, "skybox_ocean");

	//camera["main"]->Orthographic(0.0f, screen_width, 0.0f, screen_height, -1.0f, 1.0f);
	camera["main"]->Perspective(45.f, 16.f / 9.f, .01f, 1000.f);
	camera["main"]->transform.Position(glm::vec3(0.0f, 1.0f, 0.0f));
	camera["main"]->transform.Rotation(0, 0, 0);
	
	sky = new Skybox();
	sky->texture = ResourceManager::GetTexture("skybox_ocean");

	Player* tPlayer = new Player();
	tPlayer->transform.Position(glm::vec3(0.0f, 0.5f, 0.0f));
	objects.push_back(tPlayer);
	opaque_objs.push_back(tPlayer);
	pObject_ptr = tPlayer;

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
	kostka->setRotationSpeed(0.0f);
	objects.push_back(kostka);
	opaque_objs.push_back(kostka);
	//NormKostka = kostka;

	kostka = new StorageCrate();
	z = rand() % 50 + 1;
	kostka->transform.Position(glm::vec3(-5.0f, 1.0f + (z / 10), -5.0f));
	kostka->setRotationDirection(glm::vec3(1, 0, -1));
	kostka->setRotationSpeed(10.0f);
	kostka->transform.parent = &objects[0]->transform;
	objects.push_back(kostka);
	opaque_objs.push_back(kostka);
	pObject2_ptr = kostka;


	Grass* tGrass = nullptr;
	for (int i = 0; i < 100; i++)
	{
		int x = (int)round(((double)(rand() % 10001 - 5000))/100.0);
		int y = (int)round(((double)((rand() % 10001) - 5000))/100.0);
		
		float rot = (float)round((double)(rand() % 36001 - 18000) / 100.0);

		tGrass = new Grass();
		tGrass->transform.Position(glm::vec3(x, 0.0f, y));
		tGrass->transform.Rotation(glm::vec3(0.0f, rot, 0.0f));
		transparent_objs.push_back(tGrass);
		this->objects.push_back(tGrass);
	}

	BuildingA* tBuild = new BuildingA();
	tBuild->transform.Position(glm::vec3(-5.0f, 0.0f, 10.0f));
	tBuild->receiveShadows = true;
	objects.push_back(tBuild);
	opaque_objs.push_back(tBuild);

	BuildingB* tBuild2 = new BuildingB();
	tBuild2->transform.Position(glm::vec3(25.0f, 0.0f, 2.0f));
	tBuild2->transform.Rotation(glm::vec3(0.0f, -90.0f, 0.0f));
	tBuild2->receiveShadows = true;
	objects.push_back(tBuild2);
	opaque_objs.push_back(tBuild2);

	Bucket *tBucket = nullptr;
	tBucket = new Bucket();
	tBucket->transform.Position(glm::vec3(-15.0f, 0.0f, 10.0f));
	tBucket->transform.Scale(2.0f, 0.5f, 2.0f);
	tBucket->receiveShadows = true;
	objects.push_back(tBucket);
	opaque_objs.push_back(tBucket);

	Water *tWater = nullptr;
	tWater = new Water();
	tWater->transform.Position(glm::vec3(-15.0f, 0.0f, 10.0f));
	tWater->transform.Scale(2.0f, 0.5f, 2.0f);
	tWater->receiveShadows = false;
	objects.push_back(tWater);
	relfective_objs.push_back(tWater);

	kostka = new StorageCrate();
	kostka->transform.Position(glm::vec3(-15.0f, 0.5f, 10.0f));
	kostka->setRotationDirection(glm::vec3(1, 0, -1));
	kostka->transform.Scale(glm::vec3(0.2f, 0.2f, 0.2f));
	kostka->setRotationSpeed(20.0f);
	objects.push_back(kostka);
	opaque_objs.push_back(kostka);


	DirectionalLight* tLight = new DirectionalLight();
	tLight->direction = glm::vec3(-0.5f, -1.0f, 1.5f);
	tLight->diffuse = glm::vec3(0.85f, 0.85f, 0.8f);
	tLight->ambient = glm::vec3(0.7f,0.7f,0.7f);
	tLight->specular = glm::vec3(1.0f, 1.0f, 1.0f);
	dirLight_ptr = tLight;

	LightManager::AddDirectionalLight(tLight);

	
}

void TestGame::Update(GLfloat dt)
{
	camera["main"]->Update(dt);
	for (auto &object : objects)
	{
		object->Update(dt);
	}

	if (Input::GetKey(Key::KEY_MINUS)) this->shininess_control -= 0.01f;
	if (shininess_control < 0.0f) shininess_control = 0.0f;

	if (Input::GetKey(Key::KEY_EQUAL)) this->shininess_control += 0.01f;
	if (shininess_control > 256.0f) shininess_control = 256.0f;

	if (Input::GetKeyDown(Key::KEY_LEFT_ALT))
	{
		if (this->mouse_mode)
		{
			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		}
		else
		{
			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		}
		mouse_mode = !mouse_mode;
	}

	pObject_ptr->transform.Scale(this->pScaleX, this->pScaleY, this->pScaleZ);

	float orbitSpeed = this->cubeOritSpeed;
	if (this->cubeOrbitDirection) orbitSpeed *= -1.0f;

	pObject2_ptr->transform.Position((float)(glm::sin(glfwGetTime()*orbitSpeed) * this->cubeOrbitRadius), (float)pObject2_ptr->transform.Position().y, (float)(glm::cos(glfwGetTime()*orbitSpeed) * this->cubeOrbitRadius));

	dirLight_ptr->diffuse = this->light_diffuse;
	dirLight_ptr->ambient = this->light_ambient;
	dirLight_ptr->specular = this->light_spec;

	dirLight_ptr->direction = glm::vec3(this->ldirX, this->ldirY, this->ldirZ);

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
