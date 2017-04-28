#pragma once

#define DllExport __declspec ( dllexport )

class DllExport test {
public:
	int testFunction();
	void MainWindow();
	void SetDirection(int i) { direction = i; }
	int GetDirection() { return direction; }
private:
	int direction = 0;
};




#define WIN32_LEAN_AND_MEAN


#include <windows.h>


#include "stdafx.h"
#include "inputclass.h"
#include "graphicsclass.h"


class Engine
{
public:
	Engine();
	Engine(const Engine&);
	~Engine();



	bool Initialize();
	void Shutdown();
	void Run();

	LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);

private:
	bool Frame();
	void InitializeWindows(int&, int&);
	void ShutdownWindows();



private:
	LPCWSTR m_applicationName;
	HINSTANCE m_hinstance;
	HWND m_hwnd;

	InputClass* m_Input;
	GraphicsClass* m_Graphics;
};


static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


static Engine* ApplicationHandle = 0;