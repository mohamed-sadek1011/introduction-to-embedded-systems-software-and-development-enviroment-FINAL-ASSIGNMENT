#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Simple make file for MultiTarget Build System
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <FILE>.i - Build <FILE>.i Preprocessed file
#      <FILE>.asm - Build <FILE>.asm Assembly file, and also build an executable c1m2.out and dump its assemply code
#      <FILE>.o - Build <FILE>.o Object file
#      compile-all - Compiles all source files into object files but does not link them into an executable
#      Build - Compile all source files and links them into an executable c1m2.out
#      Clean - Removes all generated files
#
# Platform Overrides:
#      PLATFORM - (MSP432, HOST)
#
#------------------------------------------------------------------------------
include sources.mk

OBJECTS:= $(SOURCES:.c=.o)
Target:=exe

# Platform Overrides
ifeq ($(PLATFORM),MSP432)

# Architectures Specific Flags
LINKER_FILE = -T msp432p401r.lds
CPU = -mcpu=cortex-m4
ARCH = -march=armv7e-m -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb
SPECS = --specs=nosys.specs

# Compiler Flags and Defines
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
LDFLAGS = -Wl,-Map=$(Target).map -Wl,$(LINKER_FILE)
CFLAGS = -Wall -g -O0 -std=c99 $(CPU) $(ARCH) $(SPECS) $(INCLUDES)
CPPFLAGS = -DMSP432 

else


# Compiler Flags and Defines
CC = gcc
LD = ld
LDFLAGS = -Wl,-Map=$(Target).map
CFLAGS = -Wall -g -O0 -std=c99 $(INCLUDES)
CPPFLAGS = -DHOST -DCOURSE1 -DVERBOSE

endif

%.i:src/%.c
	$(CC) $(CPPFLAGS) $(INCLUDES) -E -o src/$@ $^

%.asm:src/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS)  -S -o src/$@ $^
	make build
	objdump -D src/$(Target).out

%.o:src/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o src/$@ $^ 

.PHONY: compile-all
compile-all: $(SOURCES)
	make $(OBJECTS)

.PHONY: build
build:$(SOURCES)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o src/$(Target).out $^
	size src/$(Target).out

.PHONY: clean
clean:
	rm -f src/*.i src/*.asm src/*.o src/*.out src/*.map





