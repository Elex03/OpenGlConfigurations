#include "window.h"

int main() {
    // Inicializar ventana
    Window window(800, 600, "Mi Ventana GLFW");

    // Bucle principal
    while (!glfwWindowShouldClose(window.getWindow())) {
        // Procesar eventos
        glfwPollEvents();

        // Renderizar
        // Aqu� pondr�as tu c�digo de renderizado
    }

    return 0;
}
