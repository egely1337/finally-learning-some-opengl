#include <App.h>

App::~App()
{
    NOT_IMPLEMENTED();
}

App::App() {
    NOT_IMPLEMENTED();
}

void App::CreateWindow(std::string WindowName, int Width, int Height)
{
    /* Set OpenGL Attritibutes */
    SDL_GL_SetAttribute (SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE); //OpenGL core profile
    SDL_GL_SetAttribute (SDL_GL_CONTEXT_MAJOR_VERSION, 3); //OpenGL 3+
    SDL_GL_SetAttribute (SDL_GL_CONTEXT_MINOR_VERSION, 3); //OpenGL 3.3

    /* Handle SDL_Init() fails. */
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        NOT_IMPLEMENTED();
    }

    /* OpenGL enable depth. */
    glEnable(GL_DEPTH);

    /* Create Window */
    m_pWindow = SDL_CreateWindow(WindowName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Width, Height, SDL_WINDOW_OPENGL);
    APP_ASSERT(m_pWindow && "Window creation failed.\n");

    /* Create Renderer */
    m_WindowRenderer = SDL_CreateRenderer(m_pWindow, 0, SDL_RendererFlags::SDL_RENDERER_ACCELERATED);
    APP_ASSERT(m_WindowRenderer && "Renderer creation failed.\n");

    /* Create Context */
    m_GLContext = SDL_GL_CreateContext(m_pWindow);
    APP_ASSERT(m_pWindow && "OpenGL Create Context.\n");

    /* Set Class Attritibutes */
    m_WindowHeight = Height;
    m_WindowWidth = Width;
    m_WindowName = WindowName;
    m_bWindowShouldClose = false;

    /* Initialize GLEW */
    glewExperimental = GL_TRUE;
    GLenum err;
    if(GLEW_OK != (err = glewInit())) {
        NOT_IMPLEMENTED();
    }
}

bool& App::IsWindowShouldClose() {
    return m_bWindowShouldClose;
}

void App::Cleanup() {
    /* Make this true, so render loop can end. */
    m_bWindowShouldClose = true;

    /* Uninitialize SDL */
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_WindowRenderer);
    SDL_GL_DeleteContext(m_GLContext);
    SDL_Quit();
}

void App::Clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void App::SwapContext()
{
    SDL_GL_SwapWindow(m_pWindow);
}

void App::WindowPollEvents()
{
    SDL_PollEvent(&m_WindowEvent);

    /* Handle Events */
    Keyboard::GetInstance().HandleEvent(m_WindowEvent);
    
    switch (m_WindowEvent.type)
    {
    case SDL_QUIT:
        Cleanup();
        break;
    default:
        break;
    }
}
