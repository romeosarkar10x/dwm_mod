#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <X11/Xlib.h>
#include "display_connection.hpp"

namespace dwm
{
    struct drawable
    {
        drawable(XID handle, const display_connection& display_connection) :
            m_handle { handle },
            m_cref_display_connection { display_connection }
        {}

        virtual ~drawable() = 0;

        operator Drawable() const noexcept
        {
            return m_handle;
        }

    protected:
        XID m_handle;
        const display_connection& m_cref_display_connection;
    };

}

#endif