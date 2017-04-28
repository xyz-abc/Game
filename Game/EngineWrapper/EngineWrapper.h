// EngineWrapper.h

#include "../Engine/Engine.h"

#pragma once

using namespace System;

namespace EngineWrapper {

	public ref class EngineWrapperClass
	{
	public :
		EngineWrapperClass();
	
		void MainWindow();
		int GetDirection(); 
		void SetDirection(int i);

	private:
		test* NativeClass;
	};
}
