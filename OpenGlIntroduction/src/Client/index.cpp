#include <Window.h>
#include <Shader.h>
#include <Arrays.h>
#include <vector>


void changePositions(GLFWwindow* window, int i = 1, int j = 0) {
	int Longitud_Array = (sizeof(arrayExample) / sizeof(*arrayExample)) / 2;
	int width, height;
	glfwGetWindowSize(window, &width, &height);

	if (j < arrayExample[(i - 1)][0] && (i - 1) != Longitud_Array)
	{
		arrayExample[i][j] = (2.0 * arrayExample[i][j]) / width - 1.0;
		arrayExample[i][(j + 1)] = 1.0 - (2.0 * arrayExample[i][(j + 1)]) / height;
		changePositions(window, i, j += 2);
	}
	if (j == arrayExample[i][0])
	{
		i += 2;
		changePositions(window, i, 0);
	}

}

int main(void)
{
	Window window(800, 600, "Mi Ventana GLFW");

	changePositions(window.getWindow());
	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), arrayExample[1], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	Shader shader("1.0,0.0,0.0,1.0");
	while (!glfwWindowShouldClose(window.getWindow())) {
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window.getWindow());
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}