#include "shader.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <glad/glad.h>

using namespace std;

Shader::Shader(const string& fileName, int shaderType)
{
	shader = glCreateShader(shaderType);

	ifstream file(fileName);
	stringstream buffer;
	
	buffer << file.rdbuf();

	auto tempStr = buffer.str();
	auto* shaderText = tempStr.c_str();

	glShaderSource(shader, 1, &shaderText, nullptr);
	glCompileShader(shader);

	int  success;
	char infoLog[512];

	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << endl;
	}

	file.close();
}

void Shader::LinkShader(uint32_t program)
{
	glAttachShader(program, shader);
}

void Shader::DeleteShader()
{
	glDeleteShader(shader);
}