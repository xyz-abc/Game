// This is the main DLL file.

#include "stdafx.h"

#include "EngineWrapper.h"
EngineWrapper::EngineWrapperClass::EngineWrapperClass()
{
	NativeEngine = new test();
}
void EngineWrapper::EngineWrapperClass::MainWindow()
{
	NativeEngine->MainWindow();
}

const float* EngineWrapper::EngineWrapperClass::getCameraRotation()
{
	return NativeEngine->GetCameraRotation();
	//return NativeEngine->GetCameraRotation();
	
}
