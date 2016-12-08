#pragma once

#include "AString.h"

namespace Alpha
{
	class INativeWindow
	{
	public:
		INativeWindow(const INativeWindow&) = delete;
		INativeWindow& operator=(const INativeWindow&) = delete;
		virtual ~INativeWindow();
	protected:
		INativeWindow();
	public:
		virtual void* GetHandle() = 0;
		virtual bool Create() = 0;
		virtual void Show() = 0;
	};
}



