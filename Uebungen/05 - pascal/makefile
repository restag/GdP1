#####################################################################
# General purpose makefile                                     		#
# 																	#
# Works for simple C-projects where:								#
# -binaries are compiles into sub-dir "bin"							#
# -binaries are created from a single c-source of identical name	#
#																	#
# Note: multiple targets in ./bin are supported						#
#																	#
#####################################################################

# add all targets in ./bin here

TARGETS += $(BIN_DIR)/pascal


#####################################################################
# No need to edit beyond this point									#
#####################################################################

# Generate debugging symbols?
CFLAGS = -g -Wall


### Fixed variable definitions
.SUFFICES:
.SUFFICES: .c .o
CC = gcc
RM_DIR = rm -rf
MKDIR = mkdir
SHELL = /bin/bash
BIN_DIR = bin
###

all: $(BIN_DIR) $(TARGETS)


### Fixed build rules
$(BIN_DIR)/% : %.c
	$(CC) $(CFLAGS) $< -o $@

$(BIN_DIR):
	$(MKDIR) $(BIN_DIR)

clean:
	$(RM_DIR) $(BIN_DIR)
