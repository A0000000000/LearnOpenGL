#include "DisplayFactory.h"
#include "GL_Program.h"
#include "VAO.h"
#include "DrawTriangles.h"
#include "FragmentShader.h"
#include "VertexShader.h"

int main(int argc, char* argv[])
{
	DisplayFactory::init(3, 3);
	DisplayFactory::setAttribute(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	Display* display = DisplayFactory::createDisplay(800, 600, "LearnOpenGL");
	display->makeThisContextCurrent();
	display->setFramebufferSizeCallback([](GLFWwindow* window, int width, int height) -> void
		{
			glViewport(0, 0, width, height);
		});

	const char* vertexShaderSource =
		"\
	        #version 330 core\n\
	        layout(location = 0) in vec3 aPos;\n\
		    void main()\n\
		    {\n\
		        gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n\
		    }\n\
		";

	const char* fragmentShaderSource1 =
		"\
			#version 330 core\n\
		        out vec4 FragColor;\n\
		    void main()\n\
		    {\n\
		        FragColor = vec4(0.4f, 0.8f, 1.0f, 1.0f);\n\
		    }\n\
		";
	const char* fragmentShaderSource2 =
		"\
			#version 330 core\n\
		        out vec4 FragColor;\n\
		    void main()\n\
		    {\n\
		        FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n\
		    }\n\
		";

	float vertices1[] =
	{
		-0.5f, -1.0f, 0.0f,
		0.5f, -1.0f, 0.0f,
		0.0f, 0.0f, 0.0f
	};
	float vertices2[] =
	{
		0.0f, 0.0f, 0.0f,
		-0.5f, 1.0f, 0.0f,
		0.5f, 1.0f, 0.0f
	};

	unsigned includes1[] = { 0, 1, 2 };
	unsigned includes2[] = { 0, 1, 2 };

	DisplayFactory::loadGLLoader();
	
	VAO vao1, vao2;
	vao1.create(1);
	vao1.genVBO(1);
	vao1.genEBO(1);
	vao1.getVBO()->setData(0, GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);
	vao1.getEBO()->setData(0, GL_ELEMENT_ARRAY_BUFFER, sizeof(includes1), includes1, GL_STATIC_DRAW);
	vao1.enableVAO();
	
	vao2.create(1);
	vao2.genVBO(1);
	vao2.genEBO(1);
	vao2.getVBO()->setData(0, GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
	vao2.getEBO()->setData(0, GL_ELEMENT_ARRAY_BUFFER, sizeof(includes2), includes2, GL_STATIC_DRAW);
	vao2.enableVAO();
	
	GL_Program program1, program2;
	VertexShader vertexShader;
	vertexShader.createShader();
	vertexShader.setSourceCode(vertexShaderSource);
	vertexShader.compileShader();

	FragmentShader fragmentShader1, fragmentShader2;
	fragmentShader1.createShader();
	fragmentShader2.createShader();

	fragmentShader1.setSourceCode(fragmentShaderSource1);
	fragmentShader2.setSourceCode(fragmentShaderSource2);

	fragmentShader1.compileShader();
	fragmentShader2.compileShader();

	program1.attachShader(vertexShader);
	program1.attachShader(fragmentShader1);
	program1.linkProgram();


	program2.attachShader(vertexShader);
	program2.attachShader(fragmentShader2);
	program2.linkProgram();

	vertexShader.deleteShader();
	fragmentShader1.deleteShader();
	fragmentShader2.deleteShader();
	
	DrawTriangles triangles1(vao1, program1), triangles2(vao2, program2);

	display->addDraw(&triangles1);
	display->addDraw(&triangles2);
	
	display->update();
	
	DisplayFactory::disposeDisplay(display);
	DisplayFactory::dispose();


	return 0;
}
