#pragma once
#include <glfw3.h>

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
	private:
		const char *m_Title;
		int m_Width, m_Height;
		GLFWwindow *m_Window;
		bool m_Closed;
	private:
		bool init();
	};
} }
