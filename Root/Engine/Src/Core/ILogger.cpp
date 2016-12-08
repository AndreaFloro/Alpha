#include <stdafx.h>
#include "ILogger.h"

namespace Alpha
{
	extern ILogger* g_Logger = nullptr;
}

using namespace Alpha;

ILogger::~ILogger()
{
}
