#pragma once

#include <vector>

#include "CMesh.h"
#include "CTransform.h"

class CModel
{
public:
	void Draw();
	CTransform transform;
	void CreateMesh(std::vector<Vertex> vertices, std::vector<uint32_t> indices);
private:
	std::vector<CMesh*> m_vMeshes;
	void CreateD3D11Mesh(std::vector<Vertex>& vertices, std::vector<uint32_t>& indices);
};