#include "GameApplication.h"

GameApplication::GameApplication()
{
	m_Window = nullptr;
	m_Running = false;
}

GameApplication::~GameApplication()
{
	destoryRenderer();
	SDL_DestroyWindow(m_Window);
	SDL_Quit();
}

bool GameApplication::init(int argc, char** argv, const string& configFilename)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		return false;
	}

	//Parse Config file
	m_Config.parse(configFilename);
	//Parse Command Line, this will override config!
	if (argc>0)
	{
		m_Commands.parse(argc, argv);
		m_Config.replace(&m_Commands);
	}

	//grab all the settings for the window
	int width = atoi(m_Config.getSetting("Window", "width").c_str());
	int height = atoi(m_Config.getSetting("Window", "height").c_str());
	string title = m_Config.getSetting("Window", "title");
	createWindow(width, height, title);

	string renderer = m_Config.getSetting("Renderer", "name");
	createRenderer(renderer);
	onInit();
	m_Running = true;
	return true;
}

bool GameApplication::createWindow(int width, int height, const string& title)
{
	//TODO: check to see if this will work for D3D
	m_Window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED,     // x position, centered
		SDL_WINDOWPOS_CENTERED,     // y position, centered
		width,                        // width, in pixels
		height,                        // height, in pixels
		SDL_WINDOW_OPENGL           // flags
		);

	return true;
}

void GameApplication::destoryRenderer()
{
	void (*destroyRenderFunc)(IRenderer*);
	destroyRenderFunc = (void(*)(IRenderer*))SDL_LoadFunction(m_RendererLib, "destoryRenderer");
	destroyRenderFunc(m_Renderer);
	SDL_UnloadObject(m_RendererLib);
}

bool GameApplication::createRenderer(const string &name)
{
	string libName = name + "Renderer.dll";
	m_RendererLib = SDL_LoadObject(libName.c_str());

	IRenderer* (*createRenderFunc)(void);

	createRenderFunc = (IRenderer* (*)(void))SDL_LoadFunction(m_RendererLib, "createRenderer");

	m_Renderer=createRenderFunc();

	return true;
}

bool GameApplication::run()
{
	while (SDL_PollEvent(&m_Event)) {
		//Get event type
		if (m_Event.type == SDL_QUIT || m_Event.type == SDL_WINDOWEVENT_CLOSE) {
			//set our boolean which controls the loop to false
			m_Running = false;
		}
	}

	return m_Running;
}