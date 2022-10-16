#include <iostream>
//Biblioteca do OpenGL
#include <GL/glew.h>
//Biblioteca que ir� desenhar a tela
#include <GLFW/glfw3.h>
//Biliotecas de valida��o
#include <cassert>
#include <array>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

//Definindo as dimen��es da janela
const int Width = 1920;
const int Heigth = 1080;

int main() {
	setlocale(LC_ALL, "pt_BR");
	//Inicializando a biblioteca do GLFW 
	assert(glfwInit() == GLFW_TRUE);

	//Construindo a janela
	GLFWwindow* window = glfwCreateWindow(Width, Heigth, "Atv. 2 Comp. Grafica - Pedro Henrique Pires Dias", nullptr, nullptr);
	//Verificar se a janela � nula
	assert(window);

	//Definindo a janela de contexto
	glfwMakeContextCurrent(window);

	//inicializa o GLEW
	int statusGlwInit = glewInit();
	std::cout << statusGlwInit << std::endl;
	assert(glewInit() == GLEW_OK);

	//Verificar a vers�o do OpenGL que est� sendo usando
	GLint GLMajorVersion = 0;
	GLint GLMinorVersion = 0;

	glGetIntegerv(GL_MAJOR_VERSION, &GLMajorVersion);
	glGetIntegerv(GL_MINOR_VERSION, &GLMinorVersion);

	std::cout << "Maior vers�o do OpenGL suportada:" << GLMajorVersion << std::endl;
	std::cout << "Menor vers�o do OpenGL suportada:" << GLMinorVersion << std::endl;

	//Obtendo informa��es do driver utilizado
	std::cout << "Fabircante do driver de video:" << glGetString(GL_VENDOR) << std::endl;
	std::cout << "Modelo da placa de video:" << glGetString(GL_RENDERER) << std::endl;
	std::cout << "Vers�o do OpenGL:" << glGetString(GL_VERSION) << std::endl;
	std::cout << "Vers�o do GLS:" << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

	//PSSO 1: Definir um tri�ngulo em coordenadas normalizadas
	std::array<glm::vec3, 3> Triangle = {
		glm::vec3{-1.0f, -1.0f, 0.0f},
		glm::vec3{ 1.0f, -1.0f, 0.0f},
		glm::vec3{ 0.0f,  1.0f, 0.0f},
	};
	
	//Aplicando o MVP
	//Criando o Model
	glm::mat4 MatrizModel = glm::identity<glm::mat4>();

	//Criando a View
	glm::vec3 Eye{0, 10, 10 };
	glm::vec3 Center{ 0, 0, 0 };
	glm::vec3 Up{ 0, 1, 0 };
	glm::mat4 MatrizView = glm::lookAt(Eye, Center, Up);

	//Criando a Projection
	constexpr float FoV = glm::radians(45.0f);
	const float AspectioRate = Width / Heigth;
	const float Near = 0.01f;
	const float Far = 1000.0f;
	glm::mat4 MatrizProjection = glm::perspective(FoV, AspectioRate, Near, Far);

	// Gerando o ModelViewProjection
	// Usando a CPU para calculo, mas o idela � usar a GPU
	glm::mat4 ModelViewProjection = MatrizProjection * MatrizView * MatrizModel;

	// Aplicando o MVP no triangulo
	for (glm::vec3& Vertice : Triangle) {
		glm::vec4 VerticeProjetado = ModelViewProjection * glm::vec4{ Vertice, 1 };

		//Calculando a coordenada homogenea
		VerticeProjetado /= VerticeProjetado.w;
		Vertice = VerticeProjetado;
	}
	//FIM - PSSO 1

	//PASSO 2: copiar os v�rtices do tri�ngulo para a mem�ria da GPU
	// Vari�vel que vai conter o identificador do buffer de v�rtices
	GLuint VertexBuffer;
	
	// Gerar um identificador glGenBuffers(NUMERO DE BUFFER, INDETIFICADOR);
	glGenBuffers(1, &VertexBuffer);

	//Ativar o buffer de v�rtices, comandos v�o afetar o VertexBuffer.
	//O buffer para onde vamos copiar os vertices do triangulo.
	glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer);

	// Passa para o OpenGL o ponteiro para os dados que ser�o copiados para GPU
	// basicamente copia os dados para a mem�ria de v�deo
	// glBufferData(ORIGEM DOS DADOS, TAMANHO EM BYTES, PONTEIRO PARA OS DADOS
	//				, TIPO DE USO DO BUFFER);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Triangle), Triangle.data(), GL_STATIC_DRAW);


	//Definir cor de fundo
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	//Construindo o loop de eventos
	while (!glfwWindowShouldClose(window)) {
		// Limpar o Buffer de cor
		glClear(GL_COLOR_BUFFER_BIT);

		// DESENHAR INICIO
		// Habilita o atributo na posi��o 0, normalmente � o atributo de v�rtices
		// Esse vai ser o identificador que vamos usar no shader para ler a posi��o
		// de cada v�rtice.
		glEnableVertexAttribArray(0);

		// Diz para o OpenGL que o VertexBuffer vai ficar associado ao atributo 0
		// glBindBuffer(TIPO, BUFFER CRIADO);
		glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer);

		// Informa ao OpenGL onde, dentro do VertexBuffer, os v�rtices est�o.
		// Neste exemplo  o array Triangles � tudo
		// glVertexAttribPointer(INDICE, QUANTIDADE DE VERTICES, TIPO
		//							, SE AS POCI��ES EST�O NORMALIZADAS, USADOS EM TEXTURAS
		//							, PONTEIRO);
		glVertexAttribPointer(0, Triangle.size(), GL_FLOAT, GL_FALSE, 0, nullptr);

		// Por fim, diz para o OpenGL desenhar o tri�ngulo
		// glDrawArrays(QUE OBJETO SER� DESENHADO, INDICE DO OBJETO
		//				, QUANTIDADE DE VERTICES PRA DESENHAR);
		glDrawArrays(GL_TRIANGLES, 0, Triangle.size());

		//Como boa pratica devemos Desliga o glBindBuffer e desabilitar o atributo da posi��o
		//Desliga o glBindBuffer
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		//desabilitar o atributo da posi��o
		glDisableVertexAttribArray(0);
		// DESENHAR FIM

		//Processa todos os eventos na fila do GLFW
		glfwPollEvents();
		//Envia o conte�do para desenhar na tela
		glfwSwapBuffers(window);
	}

	//Desalocar o VertexBuffer da mem�ria de video
	glDeleteBuffers(1, &VertexBuffer);

	//Finaliza a biblioteca GLFW
	glfwTerminate();
	return 0;
}
