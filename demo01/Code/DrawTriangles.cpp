#include "DrawTriangles.h"

DrawTriangles::DrawTriangles(VAO& vao, GL_Program& program, int pos)
{
	this->vao = vao;
	this->program = program;
	this->pos = pos;
}

DrawTriangles::DrawTriangles(VAO&& vao, GL_Program&& program, int pos)
{
	this->vao = vao;
	this->program = program;
	this->pos = pos;
}

void DrawTriangles::draw()
{
	glUseProgram(this->program.getProgram());
	int count;
	unsigned* vaoID = this->vao.getVAOID(&count);
	if (this->pos >= count)
	{
		throw "数组索引超出数组长度";
	}
	glBindVertexArray(vaoID[this->pos]);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);
}

void DrawTriangles::dispose()
{
	
}
