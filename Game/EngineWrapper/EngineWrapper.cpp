// This is the main DLL file.

#include "stdafx.h"

#include "EngineWrapper.h"
EngineWrapper::EngineWrapperClass::EngineWrapperClass()
{
	NativeClass = new test();
}
void EngineWrapper::EngineWrapperClass::MainWindow()
{
	NativeClass->MainWindow();
}

int EngineWrapper::EngineWrapperClass::GetDirection()
{
	return NativeClass->GetDirection();
}

void EngineWrapper::EngineWrapperClass::SetDirection(int i)
{
	NativeClass->SetDirection(i);
}