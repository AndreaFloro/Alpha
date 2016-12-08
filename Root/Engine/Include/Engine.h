#ifndef _ENGINE_H
#define _ENGINE_H

//#include "Core\INativeWindow.h"

namespace Alpha
{
	class INativeWindow;

	struct ARESULT
	{
		enum AStatus
		{
			SUCCESS,
			FAILURE
		};
		AStatus status;
	};
	//Forward declarations
	class Logger;

	class Engine
	{
	public:
		static bool BuildWindowsStandaloneEngine();
		~Engine();
	public:
		ARESULT Initialize();
		void Start();
	private:
		Engine();
		//Singleton instance!
		static Engine* s_instance;
		//Deleted copy ctor and copy assignment operator
		Engine(const Engine&) = delete;
		Engine& operator=(const Engine&) = delete;
		//Tmp
		INativeWindow* _window;
	};

	extern Alpha::Engine* g_Engine;	
}


#endif // !_ENGINE_H
