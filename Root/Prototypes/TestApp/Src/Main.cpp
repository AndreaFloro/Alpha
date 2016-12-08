#pragma comment(lib, "Engine")

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN       
#endif // !WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include "..\..\..\Engine\Include\Engine.h"

using namespace Alpha;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	
	if (!Engine::BuildWindowsStandaloneEngine())
	{
		return -1;
	}

	if (g_Engine == nullptr)
	{
		return -1;
	}
	//Engine created!!

	//Init the engine
	if (g_Engine->Initialize().status == ARESULT::FAILURE)
	{
		return -1;
	}

	//Start the Engine
	g_Engine->Start();

	return 0;
}