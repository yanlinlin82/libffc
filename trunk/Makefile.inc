# Makefile.inc

#--------------------------------------------------------------------------

COMMAND_PREFIX	= i586-mingw32msvc-

CC	= $(COMMAND_PREFIX)g++
RC	= $(COMMAND_PREFIX)windres
AR	= $(COMMAND_PREFIX)ar

#--------------------------------------------------------------------------
# Check make type

ifeq ("$(MAKECMDGOALS)", "debug")
CONFIG := Debug
DEPEND := 1
endif

ifeq ("$(MAKECMDGOALS)", "clean_debug")
CONFIG := Debug
DEPEND :=
endif

ifeq ("$(MAKECMDGOALS)", "release")
CONFIG := Release
DEPEND := 1
endif

ifeq ("$(MAKECMDGOALS)", "clean_release")
CONFIG := Release
DEPEND :=
endif

#--------------------------------------------------------------------------

CFLAGS	= -c -W -Wall -Werror
LFLAGS	= -W -Wall

ifeq ("$(MAKECMDGOALS)", "debug")
CFLAGS += -D_DEBUG -g
LFLAGS += -D_DEBUG -g
endif

ifeq ("$(MAKECMDGOALS)", "release")
CFLAGS += -DNDEBUG -O4
LFLAGS += -DNDEBUG -O4
endif

#--------------------------------------------------------------------------

INC_DIR	= $(ROOT)Include/
TMP_DIR	= $(ROOT)Temporary/
LIB_DIR	= $(ROOT)Library/
OUT_DIR	= $(ROOT)Output/

#--------------------------------------------------------------------------

.PHONY: help
.PHONY: all
.PHONY: clean
.PHONY: debug
.PHONY: release
.PHONY: clean_debug
.PHONY: clean_release

help:
	@echo "make { help | all | clean | debug | release | clean_debug | clean_release }"

all:
	$(MAKE) debug
	$(MAKE) release

clean:
	$(MAKE) clean_debug
	$(MAKE) clean_release

#--------------------------------------------------------------------------
