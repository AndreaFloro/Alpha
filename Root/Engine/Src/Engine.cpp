#include "stdafx.h"
#include "..\Include\Engine.h"
#include "Core\ILogger.h"
#include "Core\WinWindow.h"

using namespace Alpha;

namespace Alpha
{
	extern Engine* g_Engine = nullptr;
}

Alpha::Engine* Engine::s_instance = nullptr;

Alpha::Engine::Engine()
{
}

bool Alpha::Engine::BuildWindowsStandaloneEngine()
{
	if (!s_instance)
	{
		s_instance = new Engine();
		g_Engine = s_instance;
	}

	return true;
}

Alpha::Engine::~Engine()
{
}

ARESULT Alpha::Engine::Initialize()
{
	ARESULT result;
	result.status = ARESULT::FAILURE;

	_window = new WinWindow();
	if (!_window->Create())
	{
		return result;
	}
	
	_window->Show();

	result.status = ARESULT::SUCCESS;
	return result;
}

void Alpha::Engine::Start()
{
	MSG msg;
	while (true)
	{
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				return;
			}

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}

