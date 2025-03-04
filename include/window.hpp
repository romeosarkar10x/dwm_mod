#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "types.hpp"
#include "drawable.hpp"
#include "display_connection.hpp"
#include <complex.h>

namespace dwm
{
    struct visual
    {

        static const visual& get_default_visual()
        {
            
        }
    
    private:
        Visual m_visual;
    };

    struct window : drawable
    {
        enum struct enum_window_class : u32 { INPUT_ONLY = InputOnly, INPUT_OUTPUT = InputOnly };
        
        window(const display_connection& display_connection, const window& parent_window, i32 pos_x, i32 pos_y, u32 width, u32 height, u32 border_width, i32 depth, enum_window_class window_class) :
            drawable(XCreateWindow(const_cast<Display*>(static_cast<const Display*>(display_connection)), static_cast<Window>(parent_window), pos_x, pos_y, width, height, border_width, ))
        {}

        operator Window() const noexcept
        {
            return m_handle;
        }

        static const window& get_root_window()
        {

        }
    };
}

#endif