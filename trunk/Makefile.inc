# Makefile.inc

CC	= i586-mingw32msvc-g++
RC	= i586-mingw32msvc-windres
AR	= i586-mingw32msvc-ar

CFLAGS	= -W -Wall -D_DEBUG
LFLAGS	= -W -Wall

INC_DIR	= $(ROOT)Include/
TMP_DIR	= $(ROOT)Temporary/
LIB_DIR	= $(ROOT)Library/
OUT_DIR	= $(ROOT)Output/

