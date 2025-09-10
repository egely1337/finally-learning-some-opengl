#include <App.h>

#include <Camera2D.h>
#include <Shader.h>
#include <Mesh.h>
#include <Texture.h>
#include <Filesystem.h>

#define VERTEX_SHADER_PATH (char*)"shaders/vertex.glsl"
#define FRAGMENT_SHADER_PATH (char*)"shaders/fragment.glsl"

/*  A NOTE FOR MYSELF:
    Firstly, I hate C++. I hate using it, I hate writing it.
    Secondly, there is a problem in Shader.cpp:13, we're getting an SIGSEGV when using stack string.
    I really need to fix this problem.

    Have a good day.
*/

App app;
Mesh mesh;

int main(int argc, char** argv) {
    /* Initialize Window & App */
    app.CreateWindow("Hello, World", 800, 600);
    Texture::Initialize();

    /* Set up mesh */
    mesh.GetShader().CreateShaderFromSource(Filesystem::ReadFile(VERTEX_SHADER_PATH), Filesystem::ReadFile(FRAGMENT_SHADER_PATH));
    mesh.Scale() = 200.f;
    mesh.Bind();

    while(!app.IsWindowShouldClose()) {
        app.Clear();

        /* Scene Begin */
        mesh.Draw();
        /* Scene End */
    
        app.SwapContext();
        app.WindowPollEvents();
    }

}