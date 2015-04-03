#include "Renderer/Renderer.h"

class OpenGLRender :public IRenderer
{
public:
	OpenGLRender();
	~OpenGLRender();

	void clear(float r, float g, float b, float a);
	void render();
};

extern "C"
{
	extern EXPORT IRenderer * createRenderer()
	{
		return new OpenGLRender();
	}

	extern EXPORT void destoryRenderer(IRenderer * renderer)
	{
		delete renderer;
		renderer = nullptr;
	}
}
