#include "src/graphics/window.h"
#include "src/maths/maths.h"

int main() {
	using namespace sparky;
	using namespace graphics;
	using namespace maths;

	Window window("Sparky", 800, 600);
	glClearColor(0.2f, 0.8f, 0.2f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	vec3 a(-0.5f, 0.0f, 0.5f);

	while (!window.closed()) {
		window.clear();

		glBegin(GL_TRIANGLES);
		glVertex2f(a.x, a.x);
		glVertex2f(a.y, a.z);
		glVertex2f(a.z, a.x);
		glEnd();

		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
		window.update();
	}

	return 0;
}
