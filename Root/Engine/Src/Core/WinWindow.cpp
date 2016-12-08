#include "stdafx.h"
#include "WinWindow.h"


using namespace Alpha;

WinWindow::WinWindow()
	:_className{ TEXT("RenderWindow") }, _title{ TEXT("Alpha Project") }
{	
}

WinWindow::~WinWindow()
{
}

HWND Alpha::WinWindow::Handle()
{
	return _hwnd;
}

void * Alpha::WinWindow::GetHandle()
{
	return static_cast<void*>(_hwnd);
}

bool Alpha::WinWindow::Create()
{
	WNDCLASSEX windowClass;
	ZeroMemory(&windowClass, sizeof(WNDCLASSEX));

	_hInstance = GetModuleHandle(NULL);
	if (_hInstance == nullptr)
		return false;
	// Fills in our window structure with the desired information of out window
	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc = WinWindow::StaticWndProc;
	windowClass.hInstance = _hInstance;
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClass.lpszClassName = _className;
	// Register our window class
	RegisterClassEx(&windowClass);

	DWORD windowStyle = WS_OVERLAPPEDWINDOW;
	// Create the window
	_hwnd = CreateWindowEx(NULL,
		windowClass.lpszClassName, // Holds the name of our window class
		_title, // Holds the title of our window
		windowStyle, // Holds our window style
		100, // X-position of our window
		100, // Y-position of our window
		1920,
		1080,
		NULL, // Holds our parent window
		NULL, // Holds our menu information
		_hInstance, // Holds our application handle
		this);

	if (!_hwnd)
	{
		return false;
	}

	return true;
}

void Alpha::WinWindow::Show()
{
	if (_hwnd != nullptr)
	{
		ShowWindow(_hwnd, SW_SHOWDEFAULT);
	}
}

LRESULT Alpha::WinWindow::StaticWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	// If this is a create message, trap the 'this' pointer passed in and store it within the window.
	if (message == WM_CREATE) SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)((CREATESTRUCT FAR *)lParam)->lpCreateParams);

	// Get the App instance from this window's user data
	WinWindow* pAppInstance = (WinWindow*)GetWindowLongPtr(hWnd, GWLP_USERDATA);

	// If we have a App instance, call it's non-static window message processing function
	if (pAppInstance) return pAppInstance->WndProc(hWnd, message, wParam, lParam);

	// If we don't have a App instance, just do default processing
	return DefWindowProc(hWnd, message, wParam, lParam);
}

LRESULT Alpha::WinWindow::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY: // When the window is closed
	{
		PostQuitMessage(0);
		return(0);
	}
	case WM_QUIT:
	case WM_CLOSE:
		// Perform default processing of this message
		return DefWindowProc(hWnd, message, wParam, lParam);

	default:
		// Perform default processing of this message
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
}
