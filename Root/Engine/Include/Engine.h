#ifndef _ENGINE_H
#define _ENGINE_H

namespace Alpha
{
	//Forward declarations
	class Logger;

	class Engine
	{
	public:
		static bool BuildWindowsStandaloneEngine();
		~Engine();
	private:
		Engine();
		//Singleton instance!
		static Engine* s_instance;
		//Deleted copy ctor and copy assignment operator
		Engine(const Engine&) = delete;
		Engine& operator=(const Engine&) = delete;
	};

	extern Alpha::Engine* g_Engine;	
}


#endif // !_ENGINE_H
