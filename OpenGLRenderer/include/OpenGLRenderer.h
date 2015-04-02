#include "../../Game/include/Renderer/Renderer.h"

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
	extern __declspec(dllexport) IRenderer * createRenderer()
	{
		return new OpenGLRender();
	}

	extern __declspec(dllexport) void destoryRenderer(IRenderer * renderer)
	{
		delete renderer;
		renderer = nullptr;
	}
}