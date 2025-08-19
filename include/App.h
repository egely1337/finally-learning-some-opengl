#ifndef APP_H
#define APP_H

#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>

#include <Definitions.h>

class App {
public:
    App();
    ~App();

    void CreateWindow(std::string WindowName, int Width, int Height);
    bool& IsWindowShouldClose();
    void WindowPollEvents();
    void Cleanup();
    void Clear();
    void SwapContext();
private:
    /* Window */
    SDL_Window* m_pWindow;
    SDL_Renderer* m_WindowRenderer;
    SDL_GLContext m_GLContext;
    SDL_Event m_WindowEvent;

    /* Window Members */
    std::string m_WindowName;
    int m_WindowWidth;
    int m_WindowHeight;
    bool m_bWindowShouldClose;
};

#endif