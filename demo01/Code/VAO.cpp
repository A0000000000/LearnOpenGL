#include "VAO.h"
#include <iostream>
VAO::VAO()
{
	this->count = 0;
	this->vaoID = nullptr;
}

VAO::VAO(const VAO& another)
{
	this->count = another.count;
	this->vaoID = new unsigned[this->count];
	memcpy(this->vaoID, another.vaoID, sizeof(unsigned) * this->count);
}

VAO& VAO::operator=(const VAO& another)
{
	if (this->vaoID != nullptr)
	{
		glDeleteVertexArrays(this->count, this->vaoID);
		delete[] this->vaoID;
		this->vaoID = nullptr;
	}
	this->count = another.count;
	this->vaoID = new unsigned[this->count];
	memcpy(this->vaoID, another.vaoID, sizeof(unsigned) * this->count);
	return *this;
}

void VAO::create(int count)
{
	this->count = count;
	this->vaoID = new unsigned[this->count];
	glGenVertexArrays(this->count, this->vaoID);
}

void VAO::genVBO(int count)
{
	this->vbo.init(this);
	this->vbo.create(count);
}

void VAO::genEBO(int count)
{
	this->ebo.init(this);
	this->ebo.create(count);
}

unsigned* VAO::getVAOID(int* count)
{
	*count = this->count;
	return this->vaoID;
}

VBO* VAO::getVBO()
{
	return &this->vbo;
}

EBO* VAO::getEBO()
{
	return &this->ebo;
}

void VAO::enableVAO(int pos)
{
	glBindVertexArray(this->vaoID[pos]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);
}


VAO::~VAO()
{
	if (this->vaoID != nullptr)
	{
		glDeleteVertexArrays(this->count, this->vaoID);
		delete[] this->vaoID;
		this->vaoID = nullptr;
	}
}
