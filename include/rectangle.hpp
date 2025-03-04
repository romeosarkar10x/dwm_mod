#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "types.hpp"

namespace dwm
{
    struct rectangle
    {
        rectangle(i32 pos_top_left_corner_x, i32 pos_top_left_corner_y, i32 width, i32 height) :
            m_pos_top_left_corner_x { pos_top_left_corner_x },
            m_pos_top_left_corner_y { pos_top_left_corner_y },
            m_width { width },
            m_height { height }
        {}
    
    private:
        i32 m_pos_top_left_corner_x, m_pos_top_left_corner_y;
        i32 m_width, m_height;
    };

}

#endif