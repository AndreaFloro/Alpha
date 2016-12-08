#ifndef _WINWINDOW_H
#define _WINWINDOW_H

#include "INativeWindow.h"
#ifndef _WINDOWS_
#define WIN32_LEAN_AND_MEAN 
#include <Windows.h>
#endif
#include "AString.h"

namespace Alpha
{

	class WinWindow : public INativeWindow
	{
	public:
		WinWindow();
		WinWindow(const WinWindow&) = delete;
		WinWindow& operator=(const WinWindow&) = delete;
		~WinWindow();
		HWND Handle();
		// Inherited via INativeWindow
	public:
		virtual void * GetHandle() override;
		virtual bool Create() override;
		virtual void Show() override;
	private:
		//Window Procedures
		static LRESULT CALLBACK	StaticWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
		LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	private:
		const achar*	_className;
		const achar*	_title;
		HWND			_hwnd;
		HINSTANCE		_hInstance;
	};
}

#endif // !_WINWINDOW_H

