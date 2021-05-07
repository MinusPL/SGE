#pragma once

class CRenderer;

class CGame
{
public:

	enum GFX_API
	{
		D3D9,
		D3D11,
		D3D12,
		VULKAN,
		OPENGL
	};

	static CRenderer* renderer;
	static GFX_API mode;
	void Init(int width, int height, HWND handle, GFX_API mode);

	CGame();
private:
	void InitD3D11();
	GLFWwindow* _window;
	int screen_width;
	int screen_height;
	HWND m_hWHANDLE;
};