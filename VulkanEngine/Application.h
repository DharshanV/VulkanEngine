#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>

class Application {
public:
	Application(const std::string& appName,uint32_t width,uint32_t height) : 
		appName(appName), width(width), height(height) {
		initWindow();
		initVulkan();
	}

	~Application() {
		cleanUp();
	}

	void run() {
		mainLoop();
	}

private:
	void initWindow() {
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		window = glfwCreateWindow(width, height, appName.c_str(), NULL, NULL);
		if (window == NULL) {
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			exit(EXIT_FAILURE);
		}
		glfwMakeContextCurrent(window);
	}

	void initVulkan() {

	}

	void mainLoop() {
		while (!glfwWindowShouldClose(window)) {
			processInput(window);

			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}

	void cleanUp() {
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void processInput(GLFWwindow* window) {
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, true);
	}

private:
	std::string appName;
	uint32_t width;
	uint32_t height;

	GLFWwindow* window;
};