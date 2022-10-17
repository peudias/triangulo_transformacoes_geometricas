#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cassert>
#include <array>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <iomanip>
#include <glm/gtx/string_cast.hpp>

const int Width = 666;
const int Heigth = 666;

void imprimirFormatado(const glm::mat4& M) {
	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout
				<< std::setw(10)
				<< std::setprecision(4)
				<< std::fixed
				<< M[i][j] << "  ";
		}
		std::cout << std::endl;
	}
}


int main() {
	setlocale(LC_ALL, "pt_BR");
	assert(glfwInit() == GLFW_TRUE);

	GLFWwindow* window = glfwCreateWindow(Width, Heigth, "Lista atv. 2", nullptr, nullptr);
	assert(window);

	glfwMakeContextCurrent(window);

	int statusGlwInit = glewInit();
	std::cout << statusGlwInit << std::endl;
	assert(glewInit() == GLEW_OK);

	GLint GLMajorVersion = 0;
	GLint GLMinorVersion = 0;

	glGetIntegerv(GL_MAJOR_VERSION, &GLMajorVersion);
	glGetIntegerv(GL_MINOR_VERSION, &GLMinorVersion);

	std::cout << "Maior versão do OpenGL suportada:" << GLMajorVersion << std::endl;
	std::cout << "Menor versão do OpenGL suportada:" << GLMinorVersion << std::endl;

	std::cout << "Fabricante do driver de video:" << glGetString(GL_VENDOR) << std::endl;
	std::cout << "Modelo da placa de video:" << glGetString(GL_RENDERER) << std::endl;
	std::cout << "Versão do OpenGL:" << glGetString(GL_VERSION) << std::endl;
	std::cout << "Versão do GLS:" << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

	glm::mat4 MIdentidade = glm::identity<glm::mat4>();
	std::cout << "Matriz Identidade" << std::endl;
	imprimirFormatado(MIdentidade);

	glm::vec3 FatorEscala{1, 3, 5};
	std::cout << "Fator de Escala:" << glm::to_string(FatorEscala) << std::endl;

	glm::mat4 MEscala = glm::rotate(MIdentidade, FatorEscala);
	std::cout << "Matriz de Escala" << std::endl;
	imprimirFormatado(MEscala);
	

	glm::vec3 pontoA = { -1.0f, -1.0f, 0.0f };
	glm::vec3 pontoB = { 1.0f, -1.0f, 0.0f };
	glm::vec3 pontoC = { 0.0f,  1.0f, 0.0f };
	
	glm::vec4 pontoA2 = MEscala * glm::vec4{pontoA, 1};
	glm::vec4 pontoB2 = MEscala * glm::vec4{pontoB, 1};
	glm::vec4 pontoC2 = MEscala * glm::vec4{pontoC, 1};

	glm::vec3 pontoA3 = {pontoA2.x, pontoA2.y, pontoA2.z};
	glm::vec3 pontoB3 = {pontoB2.x, pontoB2.y, pontoB2.z};
	glm::vec3 pontoC3 = {pontoC2.x, pontoC2.y, pontoC2.z};

	std::array<glm::vec3, 3> Triangle = {pontoA3, pontoB3, pontoC3};
	
	glm::mat4 MatrizModel = glm::identity<glm::mat4>();

	glm::vec3 Eye{0, 10, 10 };
	glm::vec3 Center{ 0, 0, 0 };
	glm::vec3 Up{ 0, 1, 0 };
	glm::mat4 MatrizView = glm::lookAt(Eye, Center, Up);

	constexpr float FoV = glm::radians(45.0f);
	const float AspectioRate = Width / Heigth;
	const float Near = 0.01f;
	const float Far = 1000.0f;
	glm::mat4 MatrizProjection = glm::perspective(FoV, AspectioRate, Near, Far);

	glm::mat4 ModelViewProjection = MatrizProjection * MatrizView * MatrizModel;

	for (glm::vec3& Vertice : Triangle) {
		glm::vec4 VerticeProjetado = ModelViewProjection * glm::vec4{ Vertice, 1 };

		VerticeProjetado /= VerticeProjetado.w;
		Vertice = VerticeProjetado;
	}

	GLuint VertexBuffer;
	
	glGenBuffers(1, &VertexBuffer);

	glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer);

	glBufferData(GL_ARRAY_BUFFER, sizeof(Triangle), Triangle.data(), GL_STATIC_DRAW);


	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);

		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer);

		glVertexAttribPointer(0, Triangle.size(), GL_FLOAT, GL_FALSE, 0, nullptr);

		glDrawArrays(GL_TRIANGLES, 0, Triangle.size());

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glDisableVertexAttribArray(0);

		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	glDeleteBuffers(1, &VertexBuffer);

	glfwTerminate();
	return 0;
}
