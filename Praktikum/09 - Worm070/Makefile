############################################################
# General purpose makefile
#
# Works for all C-projects where
# - binaries are compiled into sub-dir bin
# - binaries are created from a multiple c-sources
#   and depend on all headers and object files in ./
#
# Note: due to the dependencies encoded multiple targets
#       are not sensible
#

# Please add all header files in ./ here
HEADERS += debug.h
HEADERS += prep.h
HEADERS += board_model.h
HEADERS += gameops.h
HEADERS += worm_model.h
HEADERS += messages.h
HEADERS += userops.h
HEADERS += worm.h

# Please add all object files in ./ here
OBJECTS += debug.o
OBJECTS += prep.o
OBJECTS += board_model.o
OBJECTS += worm_model.o
OBJECTS += messages.o
OBJECTS += userops.o
OBJECTS += gameops.o
OBJECTS += worm.o

# Please add THE target in ./bin here
TARGET += $(BIN_DIR)/worm
 
#################################################
# There is no need to edit below this line
#################################################

# Generate debugging symbols?
CFLAGS = -g -Wall
# set appropriate library for curses
ifeq ($(MSYSTEM),MINGW32)
    LDLIBS = -lpdcurses
else
    LDLIBS = -lncurses
endif

#### Fixed variable definitions
.SUFFICES:
.SUFFICES: .c .o
CC = gcc
RM_DIR = rm -rf
MKDIR = mkdir
SHELL = /bin/bash
BIN_DIR = bin

#### Default target
all: $(BIN_DIR) $(TARGET)

#### Fixed build rules for binaries with multiple object files

# Object files
%.o : %.c $(HEADERS)
	$(CC) -c $(CFLAGS) $< 

#### Binaries
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(LDLIBS)

#### Fixed build rule for a monolithic C-File (only one source file per binary)
#$(BIN_DIR)/% : %.c %.h
#	$(CC) $(CFLAGS) $< -o $@ $(LDLIBS)

$(BIN_DIR):
	$(MKDIR) $(BIN_DIR)

.PHONY: clean
clean :
	$(RM_DIR) $(BIN_DIR) $(OBJECTS)

