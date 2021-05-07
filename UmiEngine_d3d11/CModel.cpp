#include "CModel.h"


#include "CD3D11Mesh.h"
#include "CGame.h"

void CModel::Draw()
{
	for (auto m_Mesh : m_vMeshes)
	{
		m_Mesh->Draw();
	}
}

void CModel::CreateMesh(std::vector<Vertex> vertices, std::vector<uint32_t> indices)
{
	switch (CGame::mode)
	{
		case CGame::GFX_API::D3D11:
		{
			CreateD3D11Mesh(vertices, indices);
		}
	}

}

void CModel::CreateD3D11Mesh(std::vector<Vertex>& vertices, std::vector<uint32_t>& indices)
{
	CD3D11Mesh* d3d11mesh = new CD3D11Mesh((CD3D11Renderer*)CGame::renderer);
	//d3d11mesh->vertices = vertices;
	//d3d11mesh->indices = indices;
	d3d11mesh->Create();
	d3d11mesh->RecalculateNormals();
	m_vMeshes.push_back(d3d11mesh);
}


