#ifndef DISPLAY_CONNECTION_HPP
#define DISPLAY_CONNECTION_HPP

#include <X11/Xlib.h>

#include "types.hpp"

namespace dwm
{
    struct display_connection
    {
        typedef void (*handler_type) (XEvent*);

        enum struct enum_event : size_t
        {
            KEY_PRESS = KeyPress,
            KEY_RELEASE = KeyRelease,
            BUTTON_PRESS = ButtonPress,
            BUTTON_RELEASE = ButtonRelease,
            MOTION_NOTIFY = MotionNotify,
            ENTER_NOTIFY = EnterNotify,
            LEAVE_NOTIFY = LeaveNotify,
            FOCUS_IN = FocusIn,
            FOCUS_OUT = FocusOut,
            KEYMAP_NOTIFY = KeymapNotify,
            EXPOSE = Expose,
            GRAPHICS_EXPOSE = GraphicsExpose,
            NO_EXPOSE = NoExpose,
            VISIBILITY_NOTIFY = VisibilityNotify,
            CREATE_NOTIFY = CreateNotify,
            DESTROY_NOTIFY = DestroyNotify,
            UNMAP_NOTIFY = UnmapNotify,
            MAP_NOTIFY = MapNotify,
            MAP_REQUEST = MapRequest,
            REPARENT_NOTIFY = ReparentNotify,
            CONFIGURE_NOTIFY = ConfigureNotify,
            CONFIGURE_REQUEST = ConfigureRequest,
            GRAVITY_NOTIFY = GravityNotify,
            RESIZE_REQUEST = ResizeRequest,
            CIRCULATE_NOTIFY = CirculateNotify,
            CIRCULATE_REQUEST = CirculateRequest,
            PROPERTY_NOTIFY = PropertyNotify,
            SELECTION_CLEAR = SelectionClear,
            SELECTION_REQUEST = SelectionRequest,
            SELECTION_NOTIFY = SelectionNotify,
            COLORMAP_NOTIFY = ColormapNotify,
            CLIENT_MESSAGE = ClientMessage,
            MAPPING_NOTIFY = MappingNotify,
            GENERIC_EVENT = GenericEvent,
            LASTEVENT = LASTEvent,
        };

        display_connection() :
            m_ptr_display { XOpenDisplay(nullptr) },
            m_default_screen_number { DefaultScreen(m_ptr_display) }
        {}

        void run_event_loop()
        {
            XEvent event;

            XSync(m_ptr_display, False);

            while(is_running && !XNextEvent(m_ptr_display, &event))
            {
                
            }

        }

        constexpr void set_event_handler(enum_event event, handler_type handler) noexcept
        {
            m_handlers[static_cast<size_t>(event)] = handler;
        }

        operator Display*() noexcept
        {
            return m_ptr_display;
        }

        operator const Display*() const noexcept
        {
            return m_ptr_display;
        }

    private:
        Display* m_ptr_display {};
        i32 m_default_screen_number;

        
        bool is_running { true };

        handler_type m_handlers[static_cast<size_t>(LASTEvent)] {};
    };

}

#endif