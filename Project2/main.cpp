//this turns off the console window
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

#include "GameManager.h"
#include "GLFW.h"
#include "Shaders.h"

int main(){
	GameManager gm;
	GLFW glfw;
	glfw.Run();
	//gm.Title();
	return 0;
}
