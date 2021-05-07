#pragma once

#include "CRenderer.h"
#include <d3d11.h>
#include <glm/glm.hpp>
#include <Windows.h>

class CD3D11Renderer : public CRenderer
{
public:
	CD3D11Renderer();
	bool Init();
	void SetWin32WindowHandle(HWND& hwnd);
	ID3D11Device* GetDevice();
	ID3D11DeviceContext* GetDeviceContext();
	void Draw();
	void BeginFrame();
	void EndFrame();
private:
	HWND hwnd;
	IDXGISwapChain* m_swapChain;
	ID3D11Device* m_device;
	ID3D11DeviceContext* m_deviceContext;
	ID3D11RenderTargetView* m_renderTargetView;
	ID3D11Texture2D* m_depthStencilBuffer;
	ID3D11DepthStencilState* m_depthStencilState;
	ID3D11DepthStencilView* m_depthStencilView;
	ID3D11RasterizerState* m_rasterState;
	/*DirectX::XMMATRIX m_projectionMatrix;
	DirectX::XMMATRIX m_worldMatrix;
	DirectX::XMMATRIX m_orthoMatrix;*/
};