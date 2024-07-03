# #!/bin/bash

# CC=g++
# CPPFLAGS="-I../Include"
# LDFLAGS=`pkg-config --libs glew`
# LDFLAGS="$LDFLAGS -lglut"

# $CC tutorial04.cpp ../Common/ogldev_util.cpp $CPPFLAGS $LDFLAGS -o tutorial04


CC=g++
CPPFLAGS="-I../Include"
LDFLAGS=`pkg-config --libs glew`
LDFLAGS="$LDFLAGS -lglut"

$CC tutorial04.cpp $CPPFLAGS $LDFLAGS -o tutorial04