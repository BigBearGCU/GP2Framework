#if defined (_WIN32)
#if defined (_MSC_VER)
#pragma warning(disable: 4251)
#endif
#if !defined(EXPORT)
#define  EXPORT __declspec(dllexport)
#endif
#else
#define EXPORT
#endif

class IRenderer
{
public:
	virtual ~IRenderer(){};

	virtual void clear(float r, float g, float b, float a) = 0;
	virtual void render() = 0;
};

extern "C"
{
	extern EXPORT IRenderer * createRenderer();
	extern EXPORT void destoryRenderer(IRenderer * renderer);
}