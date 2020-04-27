#pragma once

#include "IShader.h"
class FragmentShader: public IShader
{
public:
	void virtual createShader() override;
	unsigned virtual getShader() override;
	void virtual setSourceCode(const char* source) override;
	void virtual compileShader() override;
	void virtual deleteShader() override;
private:
	unsigned shader;
	const char* source;
};

