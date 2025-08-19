#include <App.h>

#include <Camera2D.h>
#include <Shader.h>
#include <Mesh.h>

/*  A NOTE FOR MYSELF:
    Firstly, I hate C++. I hate using it, I hate writing it.
    Secondly, there is a problem in Shader.cpp:13, we getting an SIGSEGV when using stack string.
    I really need to fix this problem.

    Have a good day.
*/

std::string VertexShader = R"(
    #version 330 core
    layout (location = 0) in vec2 aPos;

    uniform mat4 MVP;
    uniform float Scale;

    void main() {
        gl_Position = MVP * vec4(aPos * Scale, 0.0, 1.0);
    }
)";

std::string FragmentShader = R"(
    #version 330 core
    out vec4 FragColor;

    void main() {
        FragColor = vec4(ColorR, 1, 1, 1.0);
    }
)";

App app;
Camera2D camera(800, 600);
Mesh mesh(VertexShader, FragmentShader);

int main(int argc, char** argv) {
    app.CreateWindow("Hello, World", 800, 600);

    //mesh.Bind();

    while(!app.IsWindowShouldClose()) {
        app.Clear();

        /* Scene Begin */

        camera.Update();
        mesh.Draw();

        /* Scene End */
        

        app.SwapContext();
        app.WindowPollEvents();
    }

}