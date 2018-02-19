#pragma once
#include "Shaders.h"

class GLFW : public Shaders {
public:
	GLFW() {}
	void Run();
private:
	
	void InitGLFW();
	int CreateWindowGLFW();
	int InitGLAD();
	void Cleanup();
	void MainLoop();
};

