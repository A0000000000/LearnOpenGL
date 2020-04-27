#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <memory>
#include "VBO.h"
#include "EBO.h"

class VAO
{
public:
	VAO();
	VAO(const VAO& another);
	VAO& operator=(const VAO& another);
	void create(int count);
	void genVBO(int count);
	void genEBO(int count);
	unsigned* getVAOID(int* count);
	VBO* getVBO();
	EBO* getEBO();
	void enableVAO(int pos = 0);
	~VAO();
private:
	unsigned* vaoID;
	int count;
	VBO vbo;
	EBO ebo;
};

