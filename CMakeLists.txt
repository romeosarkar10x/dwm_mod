cmake_minimum_required(VERSION 3.20)
project(dwm VERSION 6.5 LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Copy `compile_commands.json` from CMAKE_BINARY_DIR to CMAKE_SOURCE_DIR
if(EXISTS "${CMAKE_BINARY_DIR}/compile_commands.json")
    execute_process(COMMAND ${CMAKE_COMMAND} -E copy
        "${CMAKE_BINARY_DIR}/compile_commands.json"
        "${CMAKE_SOURCE_DIR}/compile_commands3.json")
endif()

set(PREFIX "/usr/local")
set(MANPREFIX "${PREFIX}/share/man")
set(VERSION "1.0")

set(X11INC "/usr/X11R6/include")
set(X11LIB "/usr/X11R6/include")

# set(XINERAMALIBS)

# set(CFLAGS -std=c99 -pedantic -Wall -Wno-deprecated-declarations -Os ${INCS} ${CPPFLAGS})
# set(LDFLAGS ${LIBS})

find_package(Freetype REQUIRED)
find_package(X11 REQUIRED)

# find_library(XINERAMA_LIB Xinerama)
find_path(XINERAMA_INCLUDE_DIRS X11/extensions/Xinerama.h)

file(GLOB_RECURSE SOURCES src/*.c)

add_executable(dwm ${SOURCES})

target_include_directories(
    dwm PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${X11_INCLUDE_DIRS}
    ${FREETYPE_INCLUDE_DIRS}
    ${XINERAMA_INCLUDE_DIRS}
)

target_compile_definitions(
    dwm PRIVATE
    VERSION="${VERSION}"
    XINERAMA
)

target_link_libraries(
    dwm PRIVATE
    ${FREETYPE_LIBRARIES}
    ${X11_LIBRARIES}
    X11 Xft Xrender Xinerama Xext Xrandr Xcursor fontconfig
)

message(STATUS "X11_LIBRARIES: ${X11_LIBRARIES}")

# set_target_properties(dwm PROPERTIES
# COMPILE_FLAGS "${CFLAGS}"
# LINK_FLAGS "${LDFLAGS}"
# )

install(TARGETS dwm DESTINATION ${PREFIX}/bin)

install(FILES "${CMAKE_SOURCE_DIR}/assets/dwm.1"
    DESTINATION "${MANPREFIX}/man1"
    RENAME "dwm.1"
)

install(CODE "
    execute_process(COMMAND mkdir -p \"${MANPREFIX}/man1\")
    execute_process(COMMAND sed \"s/VERSION/${VERSION}/g\" -i \"${MANPREFIX}/man1/dwm.1\")
    execute_process(COMMAND chmod 644 \"${MANPREFIX}/man1/dwm.1\")
")