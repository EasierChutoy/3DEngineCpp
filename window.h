//
// Created by liam on 5/18/16.
//

#ifndef INC_3DGAMEENGINE_WINDOW_H
#define INC_3DGAMEENGINE_WINDOW_H

#include <string>
#include <SDL2/SDL.h>

class Window
{
public:
    Window(int width, int height, const std::string& title);

    void Update();
    bool IsClosed();

    virtual ~Window();
private:
    SDL_Window* m_window;
    SDL_GLContext  m_glContext;
    bool m_isClosed;


};


#endif //INC_3DGAMEENGINE_WINDOW_H
