#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <memory>

class VAO;

class EBO
{
public:
	EBO();
	EBO(const EBO& another);
	EBO& operator=(const EBO& another);
	void init(VAO* vao);
	void create(int count);
	void setData(int pos, unsigned type, long long int length, void* data, unsigned dataType);
	~EBO();
private:
	VAO* vao;
	int count;
	unsigned* eboID;
};

