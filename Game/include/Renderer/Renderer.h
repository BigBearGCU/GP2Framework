class IRenderer
{
public:
	virtual ~IRenderer(){};

	virtual void clear(float r, float g, float b, float a) = 0;
	virtual void render() = 0;
};

extern "C"
{
	extern __declspec(dllexport) IRenderer * createRenderer();
	extern __declspec(dllexport) void destoryRenderer(IRenderer * renderer);
}