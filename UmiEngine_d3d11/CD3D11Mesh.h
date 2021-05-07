#pragma once

#include "CMesh.h"
#include "CD3D11Renderer.h"
#include <d3d11.h>
//#include <directxmath.h>
//using namespace DirectX;

class CD3D11Mesh : public CMesh
{
public:
	CD3D11Mesh(CD3D11Renderer* renderer);
	bool Create();
	void Draw();
private:
	ID3D11Buffer* m_vertexBuffer, * m_indexBuffer;
	CD3D11Renderer* renderer;
};