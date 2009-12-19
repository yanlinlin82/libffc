# Makefile.inc

#--------------------------------------------------------------------------

PLATFORM := $(shell uname)

ifeq ("$(PLATFORM)", "Linux")
COMMAND_PREFIX	= i586-mingw32msvc-
endif

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

TMP_PATH = $(TMP_DIR)$(PLATFORM)/$(CONFIG)/
LIB_PATH = $(LIB_DIR)$(PLATFORM)/$(CONFIG)/
OUT_PATH = $(OUT_DIR)$(PLATFORM)/$(CONFIG)/

ALL_DIR	= $(shell find $(TMP_DIR) $(LIB_DIR) $(OUT_DIR) -type d | sort --reverse)

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
	rmdir -v --ignore-fail-on-non-empty $(ALL_DIR)

#--------------------------------------------------------------------------

