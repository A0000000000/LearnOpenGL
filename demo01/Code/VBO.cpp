#include "VBO.h"
#include "VAO.h"
VBO::VBO()
{
	this->count = 0;
	this->vboID = nullptr;
}

VBO::VBO(const VBO& another)
{
	this->count = another.count;
	this->vboID = new unsigned[this->count];
	memcpy(this->vboID, another.vboID, sizeof(unsigned) * this->count);
}

VBO& VBO::operator=(const VBO& another)
{
	if (this->vboID != nullptr)
	{
		glDeleteBuffers(this->count, this->vboID);
		delete[] this->vboID;
		this->vboID = nullptr;
	}
	this->count = another.count;
	this->vboID = new unsigned[this->count];
	memcpy(this->vboID, another.vboID, sizeof(unsigned) * this->count);
	return *this;
}

void VBO::init(VAO* vao)
{
	this->vao = vao;
}

void VBO::create(int count)
{
	this->count = count;
	this->vboID = new unsigned[this->count];
	glGenBuffers(this->count, this->vboID);
}

void VBO::setData(int pos, unsigned type, long long length, void* data, unsigned dataType)
{
	if (pos >= this->count)
	{
		throw "数组索引超出数组长度";
	}
	int vaoCount;
	unsigned* vaoID = this->vao->getVAOID(&vaoCount);
	if (pos >= vaoCount)
	{
		throw "数组索引超出数组长度";
	}
	glBindVertexArray(vaoID[pos]);
	glBindBuffer(type, this->vboID[pos]);
	glBufferData(type, length, data, dataType);
	glBindVertexArray(0);
}

VBO::~VBO()
{
	if (this->vboID != nullptr)
	{
		glDeleteBuffers(this->count, this->vboID);
		delete[] this->vboID;
		this->vboID = nullptr;
	}
}
