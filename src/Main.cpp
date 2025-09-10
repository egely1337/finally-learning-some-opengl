#include <App.h>

#include <Camera2D.h>
#include <Shader.h>
#include <Mesh.h>
#include <Texture.h>

/*  A NOTE FOR MYSELF:
    Firstly, I hate C++. I hate using it, I hate writing it.
    Secondly, there is a problem in Shader.cpp:13, we're getting an SIGSEGV when using stack string.
    I really need to fix this problem.

    Have a good day.
*/

std::string VertexShader = R"(
    #version 330 core
    layout (location = 0) in vec2 aPos;
    layout (location = 1) in vec3 aColor;
    layout (location = 2) in vec2 aTexPos;

    uniform mat4 MVP;
    uniform float Scale;

    out vec3 Color;
    out vec2 TexCoord;

    void main() {
        gl_Position = MVP * vec4(aPos * Scale , 0.0, 1.0);
        
        Color = aColor;
        TexCoord = aTexPos;
    }
)";

std::string FragmentShader = R"(
    #version 330 core

    /* In & Out */
    in vec3 Color;
    in vec2 TexCoord;
    out vec4 FragColor;

    /* Our Texture */
    uniform sampler2D Texture;

    void main() {
        FragColor = texture(Texture, TexCoord);
    }
)";

App app;
Mesh mesh;

int main(int argc, char** argv) {
    /* Initialize Window & App */
    app.CreateWindow("Hello, World", 800, 600);
    Texture::Initialize();

    /* Set up mesh */
    mesh.GetShader().CreateShaderFromSource(VertexShader, FragmentShader);
    mesh.Scale() = 500.f;
    mesh.Bind();

    while(!app.IsWindowShouldClose()) {
        app.Clear();

        /* Scene Begin */

        if(Keyboard::GetInstance().IsPressed(KbdKeycodes::KEYCODE_A)) {
            std::cout << "Hello!" << std::endl;
        }

        mesh.Draw();

        /* Scene End */
    
        app.SwapContext();
        app.WindowPollEvents();
    }

}