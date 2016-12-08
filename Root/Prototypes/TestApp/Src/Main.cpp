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
		return 1;
	}
	//Engine created!!

	

	return 0;
}