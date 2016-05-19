#include <iostream>
#include "window.h"
#include <GL/glew.h>

int main()
{
    Window window(800, 600, "3D Engine");

    while(!window.IsClosed())
    {
        glClearColor(0.0f, 0.15f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        window.Update();
    }

    return 0;
}
