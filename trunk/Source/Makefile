ROOT	= ../

include $(ROOT)Makefile.inc

PROJECT	= libffc
TARGET	= $(LIB_DIR)$(PROJECT).a
MODULES	= $(wildcard *.cpp)
HEADERS	= $(wildcard $(INC_DIR)*.h)

OBJECTS	= $(MODULES:%.cpp=$(TMP_DIR)$(PROJECT)/%.o)

.PHONY: all
.PHONY: clean

all: $(TARGET)

clean:
	rm -rf $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	@[ -d $(@D) ] || mkdir -pv $(@D)
	$(AR) crv $@ $^

$(TMP_DIR)$(PROJECT)/%.o: %.cpp $(HEADERS)
	@[ -d $(@D) ] || mkdir -pv $(@D)
	$(CC) -c $(CFLAGS) $(INC_DIR:%=-I%) $< -o $@

