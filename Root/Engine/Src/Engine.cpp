#include "stdafx.h"
#include "..\Include\Engine.h"
#include "Logger.h"

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

