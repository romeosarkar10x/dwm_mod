#ifndef DRAWING_CONTEXT_HPP
#define DRAWING_CONTEXT_HPP

#include "types.hpp"
#include "display_connection.hpp"

namespace dwm
{
    struct drawing_context
    {
        drawing_context(const display_connection& display_connection) :
            m_cref_display_connection { display_connection }
        {}

        void resize_drawable_area(u32 new_width, u32 new_height) noexcept
        {
            m_width_drawable_area = new_width;
            m_height_drawable_area = new_height;

            // XFreePixmap(const_cast<Display*>(static_cast<const Display*>(m_cref_display_connection)), m_drawable);
            // XCreatePixmap(const_cast<Display*>(static_cast<const Display*>(m_cref_display_connection)), m_drawable, 
        }

    private:
        u32 m_width_drawable_area, m_height_drawable_area;
        const display_connection& m_cref_display_connection;

        i32 m_screen_number;
        Window m_handle_root_window;
        GC m_graphics_context;
    };
}

#endif