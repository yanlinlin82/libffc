# Makefile

ROOT	= ../../

include $(ROOT)Makefile.inc

#--------------------------------------------------------------------------

LFLAGS		+= -mwindows -u _WinMain@16

PROJECT		= HelloDemo
TARGET		= $(OUT_PATH)$(PROJECT).exe
MODULES		= $(wildcard *.cpp)
RESOURCE	= $(wildcard *.rc)
LIBS		= ffc

#--------------------------------------------------------------------------

include $(ROOT)Makefile.rules

#--------------------------------------------------------------------------

