#include <string>

#include <SDL.h>

#include "Utils/ConfigParser.h"
#include "Utils/CommandLineParser.h"

#include "Renderer/Renderer.h"

using namespace std;

class GameApplication
{
public:
	GameApplication();
	virtual ~GameApplication();

	bool init(int argc, char** argv, const string& configFilename = "config.ini");
	bool createWindow(int width, int height, const string& title);
	bool createRenderer(const string &name);

	virtual void onInit(){};

	bool run();
private:
	void destoryRenderer();
protected:
	ConfigParser m_Config;
	CommandLineParser m_Commands;

	SDL_Window * m_Window;
	SDL_Event m_Event;

	IRenderer *m_Renderer;
	void *m_RendererLib;

	bool m_Running;
};
