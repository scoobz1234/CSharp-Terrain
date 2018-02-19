#include "GLFW.h"

#define GLFW_WINDOW_HEIGHT 600
#define GLFW_WINDOW_WIDTH 800
#define GLFW_WINDOW_NAME "The Tomb"

#define WINDOW_COLOR_BLUE false
#define WINDOW_COLOR_RED false
#define WINDOW_COLOR_BLACK true
#define WINDOW_COLOR_CHANGING false
#define DRAW_TRIANGLE false
#define DRAW_RECTANGLE true


GLFWwindow* window;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

//Init GLFW set versions and profiles
void GLFW::InitGLFW() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

// glfw window creation
int GLFW::CreateWindowGLFW() {
	window = glfwCreateWindow(GLFW_WINDOW_HEIGHT, GLFW_WINDOW_HEIGHT,GLFW_WINDOW_NAME, NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	return 0;
}

// glad: load all OpenGL function pointers
int GLFW::InitGLAD() {
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	return 0;
}

//gets rid of all that clutter..
void GLFW::Cleanup() {
	glfwDestroyWindow(window);
	glfwTerminate();
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}

// whenever the window size changes this callback function executes
void framebuffer_size_callback(GLFWwindow* window, int width, int height){
	glViewport(0, 0, width, height);
}

// main loop that checks for resize and if the window has been closed
void GLFW::MainLoop() {
	while (!glfwWindowShouldClose(window)) {
		//checking for input
		processInput(window);
		//render
		if (WINDOW_COLOR_BLACK) {
			glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		}
		else if (WINDOW_COLOR_RED) {
			glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
		}
		else if (WINDOW_COLOR_BLUE) {
			glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
		}
		else {
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		}
		glClear(GL_COLOR_BUFFER_BIT);

			//do some color changing!!!
		if (WINDOW_COLOR_CHANGING) {
			float timeValue = glfwGetTime();
			float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
			float blueValue = (sin(timeValue) / 1.0f) + 0.5f;
			float redValue = (sin(timeValue) / 1.5f) + 0.5f;
			int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
			glUniform4f(vertexColorLocation, redValue, greenValue, blueValue, 1.0f);
		}
			glUseProgram(shaderProgram);
			glBindVertexArray(VAO);
			
			//draw triangle
		if (DRAW_TRIANGLE) {
			glDrawArrays(GL_TRIANGLES, 0, 3);
		}

			//draw square
		if (DRAW_RECTANGLE) {
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
			glBindVertexArray(0); // no need to unbind it every time
		}

		//swap buffers and poll IO events
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	// terminate, clearing all previously allocated GLFW resources.
	glfwTerminate();
}

// gameLoop
void GLFW::Run() {
	InitGLFW();
	CreateWindowGLFW();
	InitGLAD();
	CreateShaders();
	GenerateBuffers();
	MainLoop();
	Cleanup();
}