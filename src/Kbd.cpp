#include <Kbd.h>

/*
 * TODO: fix this shit.
 *
 */

Keyboard Keyboard::GetInstance()
{
    static Keyboard keyboard;
    return keyboard;
}

void Keyboard::HandleEvent(SDL_Event &Event)
{
    switch (Event.type)
    {
        case SDL_KEYDOWN:
            m_Keys[Event.key.keysym.scancode].m_IsPressed = true;
        case SDL_KEYUP:
            m_Keys[Event.key.keysym.scancode].m_IsPressed = false;
        default:
            break;
    }
}

bool Keyboard::IsPressed(KbdKeycodes Keycode)
{
    return m_Keys[Keycode].m_IsPressed;
}
