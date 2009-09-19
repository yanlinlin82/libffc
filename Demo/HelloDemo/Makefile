# Makefile

ROOT	= ../../

include $(ROOT)Makefile.inc

#--------------------------------------------------------------------------

LFLAGS		+= -mwindows -u _WinMain@16

PROJECT		= HelloDemo
TARGET		= $(OUT_DIR)$(CONFIG)/$(PROJECT).exe
MODULES		= $(wildcard *.cpp)
RESOURCE	= $(wildcard *.rc)
LIBS		= ffc ole32

#--------------------------------------------------------------------------

include $(ROOT)Makefile.rules

#--------------------------------------------------------------------------
