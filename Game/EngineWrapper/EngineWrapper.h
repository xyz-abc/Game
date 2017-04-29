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
		//const float* getCameraRotation();
		System::Tuple<float, float, float>^ getCameraRotation();
		void setCameraRotation(float x, float y, float z);
		void deltaCameraRotation(float x, float y, float z);
		void deltaCameraPosition(float x, float y, float z);
	private:
		test* NativeEngine;
	};
}
