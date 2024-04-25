#include <Window.h>


/*If you can use this function, you should add this line in your main file 
	glfwSetCursorPosCallback(window.getWindow(), cursor_position_callback);
  you must pass the screen pointer as an argument
*/
void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
	int width, height;

	glfwGetWindowSize(window, &width, &height);

	double x_normalized = (2.0 * xpos) / width - 1.0;
	double y_normalized = 1.0 - (2.0 * ypos) / height;

	std::cout << "Coordenadas en openGl: (" << x_normalized << ", " << y_normalized << ")" << std::endl;
}
