#include "Shaders.h"

extern bool DRAW_TRIANGLE;

const char *vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec3 aColor;\n"
"out vec3 ourColor;"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos, 1.0);\n"
"	ourColor = aColor;\n"
"}\0";

const char *fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"in vec3 ourColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(ourColor,1.0);\n"
"}\n\0";

//VBO vertices
float vertices[]{
	  // positions         // colors
	 0.5f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f,    // top right
	 0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom right
	-0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,   // bottom left
	-0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 0.0f,    // top left
	// 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // top 

};


//EBO indices
unsigned int indices[] = {  // note start from 0!
	0, 1, 3,   // first triangle
	1, 2, 3    // second triangle
};

void Shaders::CreateShaders() {
	//create vertex shader...
	int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	//check if shader creation was successful..
	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

	if (!success) {
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	//create fragment shader....
	int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

	if (!success) {
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	// link shaders...
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	//check for linking problems/errors
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shaders::GenerateBuffers() {

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	//bind the vertex array object first, 
	//then bind and set vertex buffers, and then configure vertex atr.
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// position attribute from aarray
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// color attribue from array
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	//not that this is allowed, the call to glVertexAttribPointer registered VBO as
	//the vertex attributes bound vertex buffer object so afterwards we can unbind safely
	//glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

	//you can unbind the VAO afterwards so other VAO calls wont accidentally modify this VAO
	//but this rarely happens. modifying other VAOS requires a call to glBindVertexArray anways
	//so we generally dont unbind VAOs nor VBOs when its not directly necessary.
	glBindVertexArray(0);

		//if you clamp to border instead of repeat use a border texure color::
	// float borderColor[] = {1.0f,1.0f,0.0f,1.0f);
	//glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);

		//uncomment to dray in wirefram
	//glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);

}
