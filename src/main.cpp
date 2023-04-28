// Graphics includes
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <iostream>
#include <vector>

#include "cpp-ui-libraries.h"

// Macro defines
#define C(x) (x ? (const char*)x : "")


  return 0;
}


static void printGLFWInfo(GLFWwindow* window) {
	int profile = glfwGetWindowAttrib(window, GLFW_OPENGL_PROFILE);
	const char* profileStr = "";
	if (profile == GLFW_OPENGL_COMPAT_PROFILE)
		profileStr = "OpenGL Compatibility Profile";
	else if (profile == GLFW_OPENGL_CORE_PROFILE)
		profileStr = "OpenGL Core Profile";

	printf("GLFW %s %s\n", glfwGetVersionString(), profileStr);
}

static bool setupOpenGL() {
	if (!gladLoadGL())
	{
		printf("Could not initialize OpenGL!\n");
		return false;
	}
	printf("OpenGL %d.%d\n", GLVersion.major, GLVersion.minor);

	std::cout << "GL_VERSION..........: " << C(glGetString(GL_VERSION)) << '\n';
	std::cout << "GL_RENDERER.........: " << C(glGetString(GL_RENDERER)) << '\n';
	std::cout << "GL_VENDOR...........: " << C(glGetString(GL_VENDOR)) << '\n';
	std::cout << "GLSL_VERSION........: " << C(glGetString(GL_SHADING_LANGUAGE_VERSION)) << '\n';
	std::cout << "-----------------------\n";

	setupStderrDebugCallback();

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glDepthFunc(GL_LEQUAL);
	glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
	return true;
}

int main(int argc, char* argv[]) {
  // Conan stuff - leave it here for now
  cpp_ui_libraries();

	glfwSetErrorCallback([](int error, const char* description) {
		fprintf(stderr, "GLFW Error %d: %s\n", error, description);
	});
	if (!glfwInit())
		return;
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

	GLFWmonitor* monitor = fullscreen ? glfwGetPrimaryMonitor() : nullptr;
	window = glfwCreateWindow((int)windowWidth, (int)windowHeight, "Main Window", monitor, nullptr);
	if (!window)
	{
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(window);
	printGLFWInfo(window);
	if (!setupOpenGL())
		exit(2);
	glfwSwapInterval(vsync);
	glfwSetKeyCallback(window, &::keyboardFunc);
	glfwSetScrollCallback(window, &::scrollFunc);

  glfwDestroyWindow(window);

  return 0;
}
