#pragma once

#include <string>
#include <vector>
#include <assimp/scene.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>

#include "Mesh.h"

class Model
{
public:
	Model(GLchar* filename);
	void Draw();
private:
	std::vector<Mesh*> meshes;
	std::string directory;
	void loadModel(std::string path);
	void processNode(aiNode *node, const aiScene *scene);
	Mesh* processMesh(aiMesh *mesh, const aiScene *scene);
};