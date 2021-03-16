#include <iostream>
#include <array>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

int WIDTH{ 800 };
int HEIGHT{ 800 };

int main ()
{
	//verifica se deu algo de errado ao inicializar o glfw
	if (!glfwInit()) 
	{
		std::cerr << " ERRO GLFW!!! " << std::endl;
		return EXIT_FAILURE;
	}

	//cria uma janela
	GLFWwindow* window{ glfwCreateWindow(WIDTH, HEIGHT, "Triangulo", nullptr, nullptr) };

	//verifica se deu algo de errado ao inicializar a window
	if (window == NULL)
	{
		std::cerr << " ERRO WINDOW!!! " << std::endl;
		return EXIT_FAILURE;
	}

	//cria o contexto OpenGL na window
	glfwMakeContextCurrent(window);

	//verifica se deu algo de errado ao inicializar o glew
	if (glewInit())
	{
		std::cerr << " ERRO GLEW!!! " << std::endl;
		return EXIT_FAILURE;
	}

	//criando trinagulo passando os vertex
	std::array<glm::vec2, 3> triangulo 
	{
		glm::vec2{ -1.0f, -1.0f }, //left
		glm::vec2{  1.0f, -1.0f }, //right
		glm::vec2{  0.0f,  1.0f }  //top
	};

	//ira armazenar os buffers do vertex 
	GLuint vertexBuffer{ 0 };

	//cria um indentificador 
	glGenBuffers(1, &vertexBuffer);

	//ativar o vertexBuffer como sendo o Buffer para onde vamos copiar os dados do triangulo.
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

	//ira armazenar na memoria da GPU o tipo que ira guardar
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangulo), triangulo.data(), GL_STATIC_DRAW);

	//define a cor do fundo
	glClearColor(0.5f, 0.5, 1.5f, 1.0f);

	//verifica se a window esta aberta
	while (!glfwWindowShouldClose(window)) 
	{
		//limpa a window
		glClear(GL_COLOR_BUFFER_BIT);

		//ativa vertex Array index
		glEnableVertexAttribArray(0);
		 
		//ira ativar o vertexBuffer no momento
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

		//define o que ira ser desenhado a partir do vertexBuffer
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);

		//ira desenhar a partir dos dados acima
		glDrawArrays(GL_TRIANGLES, 0, 3);
		//inicia os eventos(input)
		glfwPollEvents();

		//troca os buffers da window
		glfwSwapBuffers(window);
	}

	//destroi a window 
	glfwDestroyWindow(window);

	//termina o contexto GLFW
	glfwTerminate();

	return EXIT_SUCCESS;
}