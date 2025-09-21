#pragma once

#include <string>

using namespace std;
struct Shader
{

	Shader(const string& fileName, int shaderType);
	void LinkShader(uint32_t program);
	void DeleteShader();

private:
	uint32_t shader;
};