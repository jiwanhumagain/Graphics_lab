#!/bin/bash

CC=g++
CPPFLAGS="-I../Include"
LDFLAGS=`pkg-config --libs glew`
LDFLAGS="$LDFLAGS -lglut"

$CC tutorial02.cpp $CPPFLAGS $LDFLAGS -o tutorial02
$CC tutorialBLA.cpp $CPPFLAGS $LDFLAGS -o tutorialBLA
$CC tutorialHISTOGRAM.cpp $CPPFLAGS $LDFLAGS -o tutorialHISTOGRAM
