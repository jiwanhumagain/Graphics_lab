# #!/bin/bash

# CC=g++
# CPPFLAGS="-I../Include"
# LDFLAGS=`pkg-config --libs glew`
# LDFLAGS="$LDFLAGS -lglut"

# $CC tutorial06.cpp ../Common/ogldev_util.cpp $CPPFLAGS $LDFLAGS -o tutorial06
# $CC Translation.cpp ../Common/ogldev_util.cpp $CPPFLAGS $LDFLAGS -o translation

CC=g++
LDFLAGS=`pkg-config --libs glew`
LDFLAGS="$LDFLAGS -lglut"

$CC rotation.cpp $LDFLAGS -o rotation
$CC translation.cpp $LDFLAGS -o translation
$CC shear.cpp $LDFLAGS -o shear
$CC scaling.cpp $LDFLAGS -o scaling
$CC orthographic.cpp $LDFLAGS -o orthographic
$CC tutorial06.cpp $LDFLAGS -o tutorial06


