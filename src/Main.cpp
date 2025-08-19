#include <App.h>
#include <Shader.h>
#include <Mesh.h>
#include <Camera2D.h>

App GApp;
Mesh mesh;
Shader MeshShader;
Camera2D camera;

    std::string VertexShader = R"(
        #version 330 core
        layout (location = 0) in vec2 aPos;
        uniform mat4 MVP;

        void main() {
            gl_Position = MVP * vec4(aPos * 0.5, 0.0, 1.0);
        }
    )";

    std::string FragmentShader = R"(
        #version 330 core
        out vec4 FragColor;

        void main() {
            // gl_FragCoord ile piksel tabanlı pseudo-zaman
            float t = mod(gl_FragCoord.x * 0.3 + gl_FragCoord.y * 0.2, 100.0); // katsayıları 10 kat artırdık

            float r = 0.5 + 0.5 * sin(t + gl_FragCoord.x * 0.5);
            float g = 0.5 + 0.5 * sin(t + gl_FragCoord.y * 0.5);
            float b = 0.5 + 0.5 * sin(t + (gl_FragCoord.x + gl_FragCoord.y) * 0.5);

            FragColor = vec4(r, g, b, 1.0);
        }
    )";


int main(int argc, char** argv) {
    GApp.CreateWindow("Hello, World", 800, 600);

    mesh.Bind();
    MeshShader.CreateShaderFromSource(VertexShader, FragmentShader);

    while(!GApp.IsWindowShouldClose()) {
        GApp.Clear();

        /* Scene Begin */

        camera.Update();
        MeshShader.SetUniform4f("MVP", (const GLfloat*)&camera.GetCameraMatrix()[0]);
        MeshShader.Bind();
        mesh.Draw();

        /* Scene End*/
        

        GApp.SwapContext();
        GApp.WindowPollEvents();
    }

}