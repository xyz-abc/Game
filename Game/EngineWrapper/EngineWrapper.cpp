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

System::Tuple<float,float,float>^ EngineWrapper::EngineWrapperClass::getCameraRotation()
{
	auto a = NativeEngine->GetCameraRotation();
	Console::Write(a[0]);
	Console::Write(a[1]);
	Console::Write(a[2]);
	auto b = gcnew System::Tuple<float, float, float>(a[0], a[1], a[2]);
	return b;
	//return NativeEngine->GetCameraRotation();
	
}

void EngineWrapper::EngineWrapperClass::setCameraRotation(float x, float y, float z)
{
	NativeEngine->SetCameraRotation(x, y, z);
}
