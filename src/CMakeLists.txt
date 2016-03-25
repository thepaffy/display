set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -Wall -std=c++11")

set(SOURCE_FILES menu.h menu.cpp menuentry.h menuentry.cpp serialdisplay.h serialdisplay.cpp display.h action.cpp action.h)

add_library(display SHARED ${SOURCE_FILES})
