#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Shaders {
public:
	void GenerateBuffers();
	void CreateShaders();
	int shaderProgram;
	unsigned int VBO;
	unsigned int VAO;
	unsigned int EBO;
	unsigned int texture;
};