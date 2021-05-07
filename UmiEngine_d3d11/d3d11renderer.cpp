#include <iostream>
#include <Windows.h>

#define GLFW_EXPOSE_NATIVE_WGL
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

#include <d3d11.h>
#include <DirectXMath.h>
#include <d3dcompiler.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3dcompiler.lib")

#include "CRenderer.h"
#include "CCamera.h"
#include "CMesh.h"
#include "CD3D11Mesh.h"
#include "CD3D11Renderer.h"
#include "CGame.h"
#include "CModel.h"

int main(int argc, char* argv)
{
	GLFWwindow* _window = nullptr;
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	_window = glfwCreateWindow(1280, 720, "UMI Engine D3D11 v0.0.1", nullptr, nullptr);
	glfwMakeContextCurrent(_window);
	HWND window = glfwGetWin32Window(_window);
	CGame* game = new CGame();
	game->Init(1280, 720, window, CGame::D3D11);

	CCamera* camera = new CCamera();
	CModel* model = new CModel();
	model->CreateMesh(std::vector<Vertex>(), std::vector<uint32_t>());


	//TODO Find better place for this shit
	ID3D11InputLayout* inputLayout = nullptr;
	ID3D10Blob* vertexShaderBuffer = nullptr;
	ID3D10Blob* pixelShaderBuffer = nullptr;
	ID3D10Blob* errorMessage = nullptr;

	ID3D11VertexShader* m_vertexShader = nullptr;
	ID3D11PixelShader* m_pixelShader = nullptr;

	HRESULT result;
	// Compile the vertex shader code.
	result = D3DCompileFromFile(L"standard.vs", NULL, NULL, "ColorVertexShader", "vs_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &vertexShaderBuffer, &errorMessage);
	if (FAILED(result))
	{
		std::cout << (char*)errorMessage->GetBufferPointer() << std::endl;
	}


	((CD3D11Renderer*)game->renderer)->GetDevice()->CreateVertexShader(vertexShaderBuffer->GetBufferPointer(), vertexShaderBuffer->GetBufferSize(), nullptr, &m_vertexShader);
	

	// Compile the pixel shader code.
	D3DCompileFromFile(L"standard.ps", NULL, NULL, "ColorPixelShader", "ps_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, &pixelShaderBuffer, &errorMessage);
	((CD3D11Renderer*)game->renderer)->GetDevice()->CreatePixelShader(pixelShaderBuffer->GetBufferPointer(), pixelShaderBuffer->GetBufferSize(), nullptr, &m_pixelShader);



	D3D11_INPUT_ELEMENT_DESC ied[] =
	{
		{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0},
		{"COLOR",    0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0},
	};

	((CD3D11Renderer*)game->renderer)->GetDevice()->CreateInputLayout(ied, ARRAYSIZE(ied), vertexShaderBuffer->GetBufferPointer(), vertexShaderBuffer->GetBufferSize(), &inputLayout);

	((CD3D11Renderer*)game->renderer)->GetDeviceContext()->IASetInputLayout(inputLayout);

	((CD3D11Renderer*)game->renderer)->GetDeviceContext()->VSSetShader(m_vertexShader, nullptr, 0);
	((CD3D11Renderer*)game->renderer)->GetDeviceContext()->PSSetShader(m_pixelShader, nullptr, 0);

	
	vertexShaderBuffer->Release();
	vertexShaderBuffer = nullptr;
	pixelShaderBuffer->Release();
	pixelShaderBuffer = nullptr;
	//END OF SHIT


	while (true)
	{
		game->renderer->BeginFrame();
		//Insert rendering objects here
		model->Draw();
		//End frame
		game->renderer->EndFrame();
		//Poll incomming events
		glfwPollEvents();
	}
}