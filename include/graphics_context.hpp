#ifndef GRAPHICS_CONTEXT_HPP
#define GRAPHICS_CONTEXT_HPP

#include <X11/Xlib.h>

#include "types.hpp"

namespace dwm
{
    struct graphics_context_values
    {
        enum struct enum_function : int 
        {
            CLEAR = GXclear,
            AND = GXand,
            AND_REVERSE = GXandReverse,
            COPY = GXcopy,
            AND_INVERTED = GXandInverted,
            NOOP = GXnoop,
            XOR = GXxor,
            OR = GXor,
            NOR = GXnor,
            EQUIV = GXequiv,
            INVERT = GXinvert,
            OR_REVERSE = GXorReverse,
            COPY_INVERTED = GXcopyInverted,
            OR_INVERTED = GXorInverted,
            NAND = GXnand,
            SET = GXset,
        };

        enum struct enum_line_style : i32
        {
            SOLID = LineSolid,
            ON_OFF_DASH = LineOnOffDash,
            DOUBLE_DASH = LineDoubleDash,
        };

        enum struct enum_cap_style : i32
        {
            

        };

// P_NOT_LAST = CapNotLast,
// P_BUTT = CapButt,
// P_ROUND = CapRound,
// P_PROJECTING = CapProjecting,
// 
// /* joinStyle */
// 
// IN_MITER = JoinMiter,
// IN_ROUND = JoinRound,
// IN_BEVEL = JoinBevel,
// 
// /* fillStyle */
// 
// LL_SOLID = FillSolid,
// LL_TILED = FillTiled,
// LL_STIPPLED = FillStippled,
// LL_OPAQUE_STIPPLED = FillOpaqueStippled,
// 
// /* fillRule */
// 
// EN_ODD_RULE = EvenOddRule,
// NDING_RULE = WindingRule,
// 
// /* subwindow mode */
// 
// IP_BY_CHILDREN = ClipByChildren,
// CLUDE_INFERIORS = IncludeInferiors,
// 
// /* SetClipRectangles ordering */
// 
// SORTED = Unsorted,
// ORTED = YSorted,
// SORTED = YXSorted,
// BANDED = YXBanded,
// 
// /* CoordinateMode for drawing routines */
// 
// #define CoordModeOrigin		0	/* relative to the origin */
// #define CoordModePrevious       1	/* relative to previous point */
// 
// /* Polygon shapes */
// 
// #define Complex			0	/* paths may intersect */
// #define Nonconvex		1	/* no paths intersect, but not convex */
// #define Convex			2	/* wholly convex */
// 
// /* Arc modes for PolyFillArc */
// 
// #define ArcChord		0	/* join endpoints of arc */
// #define ArcPieSlice		1	/* join endpoints to center of arc */
// 
        // };
        
        graphics_context_values() = default;

        void set_function(enum_function function)
        {
            m_values.function = static_cast<i32>(function);
            // m_mask |= 
        }

        void set_plane_mask(u64 plane_mask)
        {
            m_values.plane_mask = plane_mask;
        }

        void set_foreground(u64 foreground)
        {
            m_values.foreground = foreground;
            m_mask |= GCForeground;
        }

        void set_background(u64 background)
        {
            m_values.background = background;
            m_mask |= GCBackground;
        }

        void set_line_width(i32 line_width)
        {
            m_values.line_width = line_width;
            m_mask |= GCLineWidth;
        }

        void set_line_style(enum_line_style line_style)
        {
            m_values.line_style = static_cast<i32>(line_style);
            m_mask |= GCLineStyle;
        }

        void set_cap_style(i32 cap_style)
        {
            m_values.cap_style = cap_style;
            m_mask |= GCCapStyle;
        }

        void set_join_style(i32 join_style)
        {
            m_values.join_style = join_style;
            m_mask |= GCJoinStyle;
        }

        void set_fill_style(i32 fill_style)
        {
            m_values.fill_style = GCFillStyle;
            m_mask |= GCFillStyle;
        }

        void set_arc_mode(i32 arc_mode)
        {
            m_values.arc_mode = arc_mode;
            m_mask |= GCArcMode;
        }

        void set_tile()
        {
            m_mask |= GCTile;
        }

        // void set_

    private:
        XGCValues m_values;
        u64 m_mask {};

    };

    struct graphics_context
    {

    private:



    };
}

#endif