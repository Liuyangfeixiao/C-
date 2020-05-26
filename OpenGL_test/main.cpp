#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<iostream>
using namespace std;

void frambuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

//setting
const char* vertexShaderSource = "#version 330 core\n";
const char* fragmentShaderSource = "#version 330 core\n";


int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{ 
		cout << "Failed to create GLFW window" << endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	//GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		cout << "Failed to initialize GLAD" << endl;
		return -1;
	}
	//glViewport(0, 0, 800, 600);
	glfwSetFramebufferSizeCallback(window, frambuffer_size_callback);
	
	//build and compile our shader program
	//------------------------------------
	//vertex shader
	int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	//check for shader complie errors
	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		cout << "ERROR::SHADER::VERTEX::COMPLIE_FAILED\n" << infoLog << endl;
	}

	//fragment shader
	
	
	
	
	//Render Loop
	while (!glfwWindowShouldClose(window))
	{
		//Input
		processInput(window);

		//Render
		glClearColor(0.2, 0.3, 0.3, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window); //交换颜色缓冲（存储着GLFW窗口的每一个像素颜色值的大缓冲）
		glfwPollEvents(); //检查有没有触发什么事件，更新窗口状态，并调用对应的回调函数
	}
	glfwTerminate();
}

void frambuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}
