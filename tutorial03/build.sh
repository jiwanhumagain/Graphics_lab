#!/bin/bash

# CC=g++
# CPPFLAGS="-I../Include"
# LDFLAGS=`pkg-config --libs glew`
# LDFLAGS="$LDFLAGS -lglut"

# $CC tutorial03.cpp $CPPFLAGS $LDFLAGS -o tutorial03
# # $CC tutorialEllipse.cpp $CPPFLAGS $LDFLAGS -o tutorialEllipse
# # $CC tutorialPolar.cpp $CPPFLAGS $LDFLAGS -o tutorialPolar


#!/bin/bash

CC=g++
CPPFLAGS="-I../Include"
LDFLAGS=`pkg-config --libs glew`
LDFLAGS="$LDFLAGS -lglut"

$CC tutorial03.cpp $CPPFLAGS $LDFLAGS -o tutorial03
# $CC tutorialEllipse.cpp $CPPFLAGS $LDFLAGS -o tutorialEllipse
# $CC tutorialPolar.cpp $CPPFLAGS $LDFLAGS -o tutorialPolar

