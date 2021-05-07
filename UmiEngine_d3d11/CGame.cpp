#include "CRenderer.h"
#include "CD3D11Renderer.h"

#include "CGame.h"

//Init static members
CRenderer* CGame::renderer = nullptr;
CGame::GFX_API CGame::mode = CGame::GFX_API::D3D11;

CGame::CGame() :
	_window(nullptr),
	screen_width(0),
	screen_height(0)
{

}

void CGame::Init(int width, int height, HWND handle, GFX_API _mode)
{
	mode = _mode;
	//Perform initialization of engine and gfx api.
	this->screen_width = width;
	this->screen_height = height;
	this->m_hWHANDLE = handle;
	
	
	switch (mode)
	{
		case GFX_API::D3D11:
		{
			InitD3D11();
			break;
		}
		default:
		{
			printf("API not supported yet...\n");
		}
	}
}

void CGame::InitD3D11()
{
	renderer = new CD3D11Renderer();
	renderer->setScreenSize(this->screen_width, this->screen_height);
	renderer->SetWin32WindowHandle(m_hWHANDLE);
	renderer->Init();
}
