# Makefile

ROOT	= ../../

include $(ROOT)Makefile.inc

#--------------------------------------------------------------------------

LFLAGS		+= -mwindows -u _WinMain@16

PROJECT		= MdiDemo
TARGET		= $(OUT_PATH)$(PROJECT).exe
MODULES		= $(wildcard *.cpp)
RESOURCE	= $(wildcard *.rc)
LIBS		= ffc ole32 comctl32

#--------------------------------------------------------------------------

include $(ROOT)Makefile.rules

#--------------------------------------------------------------------------

