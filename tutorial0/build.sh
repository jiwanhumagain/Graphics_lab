#!/bin/bash

CC=g++
LDFLAGS=`pkg-config --libs glew`
LDFLAGS="$LDFLAGS -lglut"

$CC tutorial01.cpp $LDFLAGS -o tutorial01
$CC subarna.cpp $LDFLAGS -o subarna
# $CC jpt.cpp $LDFLAGS -o jpt



# #include <X11/Xlib.h>
# #include <iostream>

# void displaySystemResolution() {
#     Display* display = XOpenDisplay(nullptr);
#     Screen* screen = DefaultScreenOfDisplay(display);
#     int screenWidth = screen->width;
#     int screenHeight = screen->height;
#     std::cout << "System Resolution: " << screenWidth << "x" << screenHeight << std::endl;
#     XCloseDisplay(display);
# }

# int main() {
#     displaySystemResolution();
#     return 0;
# }



