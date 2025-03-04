#ifndef FONT_HPP
#define FONT_HPP

#include <X11/Xlib.h>

#include "list.hpp"

namespace dwm
{
    struct font
    {
        Display* m_ptr_display;



    };

    using font_list = list<font>;
}

#endif