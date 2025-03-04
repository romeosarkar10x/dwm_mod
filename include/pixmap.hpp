#ifndef PIXMAP_HPP
#define PIXMAP_HPP

#include <iostream>
#include <X11/X.h>

#include "display_connection.hpp"
#include "drawable.hpp"
#include "types.hpp"

namespace dwm
{
    struct pixmap : drawable
    {
        pixmap(const display_connection& display_connection, const drawable& parent, const u32 width, const u32 height, const u32 depth) :
            drawable(XCreatePixmap(const_cast<Display*>(static_cast<const Display*>(display_connection)), static_cast<Drawable>(parent), width, height, depth), display_connection)
        {}

        ~pixmap()
        {
            if(!XFreePixmap(const_cast<Display*>(static_cast<const Display*>(m_cref_display_connection)), m_handle))
            {
                std::cout << "failed to free Pixmap" << std::endl;
            }
        }

        const pixmap& get_root_pixmap()
        {
            None;

        }
    };


}

#endif