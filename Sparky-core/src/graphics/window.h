#pragma once
#include <GL/glew.h>
#include <glfw3.h>
#define MAX_KEYS	   1024
#define MAX_MOUSE_KEYS 32
#include <iostream>

namespace sparky { namespace graphics {
	class Window {
	public:
		Window(const char* title, int width, int height);
		~Window();

		void update();
		void clear() const;
		bool closed() const;

		inline int getWidth() const { return m_Width; }
		inline int getHeight() const { return m_Height; }

		bool isKeyPressed(unsigned int keyCode) const;
		bool isMouseButtonPressed(unsigned int button) const;
		void getMousePosition(double& x, double& y) const;
	private:
		const char *m_Title;
		int m_Width, m_Height;
		GLFWwindow *m_Window;
		bool m_Closed;

		bool m_Keys[MAX_KEYS];
		bool m_MouseButtons[MAX_MOUSE_KEYS];
		double mx, my;
	private:
		bool init();
		friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		friend static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		friend static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
	};
} }
