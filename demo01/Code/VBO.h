#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <memory>

class VAO;

class VBO
{
public:
	VBO();
	VBO(const VBO& another);
	VBO& operator=(const VBO& another);
	void init(VAO* vao);
	void create(int count);
	void setData(int pos, unsigned type, long long int length, void* data, unsigned dataType);
	~VBO();
private:
	VAO* vao;
	int count;
	unsigned* vboID;
};

