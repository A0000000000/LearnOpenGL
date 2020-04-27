#include "EBO.h"
#include "VAO.h"
EBO::EBO()
{
	this->count = 0;
	this->eboID = nullptr;
}

EBO::EBO(const EBO& another)
{
	this->count = another.count;
	this->eboID = new unsigned[this->count];
	memcpy(this->eboID, another.eboID, sizeof(unsigned) * this->count);
}

EBO& EBO::operator=(const EBO& another)
{
	if (this->eboID != nullptr)
	{
		glDeleteBuffers(this->count, this->eboID);
		delete[] this->eboID;
		this->eboID = nullptr;
	}

	this->count = another.count;
	this->eboID = new unsigned[this->count];
	memcpy(this->eboID, another.eboID, sizeof(unsigned) * this->count);
	return *this;
}

void EBO::init(VAO* vao)
{
	this->vao = vao;
}

void EBO::create(int count)
{
	this->count = count;
	this->eboID = new unsigned[this->count];
	glGenBuffers(this->count, this->eboID);
}

void EBO::setData(int pos, unsigned type, long long length, void* data, unsigned dataType)
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
	glBindBuffer(type, this->eboID[pos]);
	glBufferData(type, length, data, dataType);
	glBindVertexArray(0);
}

EBO::~EBO()
{
	if (this->eboID != nullptr)
	{
		glDeleteBuffers(this->count, this->eboID);
		delete[] this->eboID;
		this->eboID = nullptr;
	}
}
