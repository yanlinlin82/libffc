ROOT	= ../../

include $(ROOT)Makefile.inc

LFALGS		+= -mconsole

PROJECT		= ConsoleDemo
TARGET		= $(OUT_DIR)$(PROJECT).exe
MODULES		= $(wildcard *.cpp)
HEADERS		= $(wildcard *.h)
RESOURCE	= $(wildcard *.rc)
LIBS		= ffc ole32

OBJECTS	= \
	$(MODULES:%.cpp=$(TMP_DIR)$(PROJECT)/%.o) \
	$(RESOURCE:%.rc=$(TMP_DIR)$(PROJECT)/%.rsc)

.PHONY: all
.PHONY: clean

all: $(TARGET)

clean:
	rm -rf $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS) $(LIB_DIR)libffc.a
	@[ -d $(@D) ] || mkdir -pv $(@D)
	$(CC) $(LFLAGS) $^ $(LIB_DIR:%=-L%) $(LIBS:%=-l%) -o $@

$(TMP_DIR)$(PROJECT)/%.o: %.cpp $(HEADERS)
	@[ -d $(@D) ] || mkdir -pv $(@D)
	$(CC) -c $(CFLAGS) $(INC_DIR:%=-I%) $< -o $@

$(TMP_DIR)$(PROJECT)/%.rsc: %.rc
	@[ -d $(@D) ] || mkdir -pv $(@D)
	$(RC) $(INC_DIR:%=-I%) $< -o $@

