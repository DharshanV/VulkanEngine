#include "Application.h"

constexpr uint32_t WIDTH = 800;
constexpr uint32_t HEIGHT = 600;

int main() {
    Application* engine = new Application("Vulkan Window", WIDTH, HEIGHT);
    engine->run();
    delete engine;
    return 0;
}