#pragma once

#include <GLFW/glfw3.h>
#include <Windows.h>
#include <string>
#include "CMesh.h"

class CRenderer
{
private:
	static CRenderer* instance;
protected:
	int m_iScreenWidth = 0;
	int m_iScreenHeight = 0;
	int m_iVideoMemory = 0;
	GLFWwindow* window = nullptr;
	std::string m_sDeviceName;
public:
	//CRenderer(CRenderer&) = delete;
	void operator=(const CRenderer&) = delete;
	virtual void Draw() = 0;
	virtual void BeginFrame() = 0;
	virtual void EndFrame() = 0;
	virtual bool Init() = 0;
	virtual void SetWin32WindowHandle(HWND& hwnd) = 0;
	void setScreenSize(int x, int y);
	static CRenderer* getInstance();
private:
};