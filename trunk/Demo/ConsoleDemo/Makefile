# Makefile

ROOT	= ../../

include $(ROOT)Makefile.inc

#--------------------------------------------------------------------------

LFLAGS		+= -mconsole

PROJECT		= ConsoleDemo
TARGET		= $(OUT_DIR)$(CONFIG)/$(PROJECT).exe
MODULES		= $(wildcard *.cpp)
RESOURCE	= $(wildcard *.rc)
LIBS		= ffc ole32

#--------------------------------------------------------------------------

include $(ROOT)Makefile.rules

#--------------------------------------------------------------------------
