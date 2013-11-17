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
HEADERS += prep.h
HEADERS += worm.h
HEADERS += messages.h
HEADERS += options.h
HEADERS += worm_model.h
HEADERS += board_model.h
HEADERS += sysworm.h

# Please add all object files in ./ here
OBJECTS += prep.o
OBJECTS += worm.o
OBJECTS += messages.o
OBJECTS += options.o
OBJECTS += worm_model.o
OBJECTS += board_model.o
OBJECTS += sysworm.o

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
CP = cp
RM_DIR = rm -rf
MKDIR = mkdir
SHELL = /bin/bash
BIN_DIR = bin
DIST_DIR = dist

#### Default target
all: $(BIN_DIR) $(TARGET)

#### Fixed build rules for binaries with multiple object files

# Object files
%.o : %.c $(HEADERS)
	$(CC) -c $(CFLAGS) $< 

#### Binaries
$(TARGET) : $(OBJECTS) $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(LDLIBS)

#### Static Binaries
static : $(OBJECTS) $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) -static $(LDLIBS)

#### Static distribution
dist : static
	$(MKDIR) -p $(DIST_DIR)
	$(CP) $(TARGET) usage.txt *.level.* $(DIST_DIR)

$(BIN_DIR):
	$(MKDIR) $(BIN_DIR)

.PHONY: clean distclean
clean :
	$(RM_DIR) $(BIN_DIR) $(OBJECTS)

distclean :
	$(RM_DIR) $(DIST_DIR)
