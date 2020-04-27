#pragma once
#include "IDraw.h"
#include "VAO.h"
#include "GL_Program.h"
class DrawTriangles: public IDraw
{
public:
	DrawTriangles(VAO& vao, GL_Program& program, int pos = 0);
	DrawTriangles(VAO&& vao, GL_Program&& program, int pos = 0);
	void virtual draw() override;
	void virtual dispose() override;
private:
	VAO vao;
	GL_Program program;
	int pos;
};

