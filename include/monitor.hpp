#ifndef MONITOR_HPP
#define MONITOR_HPP

#include "list.hpp"
#include "rectangle.hpp"
// #include "client.hpp"
// #include ""
namespace dwm
{
    struct monitor
    {
        enum enum_bar_position : char { TOP, BOTTOM };
        
        
    private:
        char m_str_layout_symbol[16u];
        double m_master_area_factor;
        i32 m_number_of_windows_in_master_area;
        i32 m_monitor_number;
        i32 m_bar_geometry_y;

        rectangle m_monitor;
        rectangle m_window;

        bool m_flag_show_bar;
        enum_bar_position m_bar_position;
        list<
    };

    using monitor_list = list<monitor>;
}

#endif