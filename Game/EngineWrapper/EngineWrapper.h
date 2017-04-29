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
		const float* getCameraRotation();

	private:
		test* NativeEngine;
	};
}
