# Makefile
# Creator: Zachary Vogel & James Pentz
# 4/30/2016
# ECEN 5013

#==================================================
# Common Configuration Section
#==================================================

# include sources makefile
include ./src/sources.mk

# initialize directory paths
OBJDIR = ./obj
SRCDIR = ./src
ASMDIR = ./asm

# set default architecture
ARCH := x86
CSTAND := temp

# toolchain
ifeq ($(ARCH), arm)
CC := /usr/bin/arm-linux-gnueabihf-gcc
LD := /usr/bin/arm-linux-gnueabihf-gcc
SIZE = arm-linux-gnueabihf-size
OBJDUMP = arm-linux-gnueabihf-objdump
else
CC := gcc
LD := gcc
SIZE = size
OBJDUMP = objdump
endif

# define flags
CFLAGS = -c -Wall -g -O0 -I$(INCDIR)
LDFLAGS = -I$(INCDIR) -Wl,-Map=./project.map
SFLAGS = -S -O0 -Wall -I$(INCDIR)

# support c99 standard
ifeq ($(CSTAND), c99)
CFLAGS += -std=c99
endif

#==================================================
# File Lists
#==================================================
# .c file dependencies (header files)
DEPS := $(wildcard $(INCDIR)/*.h)

# .o file list
OBJS := $(SRCS:%.c=$(OBJDIR)/%.o)

# .S/.asm file list
SMS := $(SRCS:%.c=$(ASMDIR)/%.S)
ASMS := $(SRCS:%.c=$(ASMDIR)/%.asm)

# .exe file list
EXE := project.exe


#==================================================
# Specific Build Targets
#==================================================
.PHONY: asm-file
asm-file: $(ASMS) $(SMS)

.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: build
build: $(OBJS)
	$(CC) $(LDFLAGS) -o ./project.exe $^
	$(OBJDUMP) -f project.exe
	$(SIZE) ./project.exe
.PHONY: upload
upload: $(EXE)
	scp $< root@192.168.7.2:

.PHONY: clean
clean:
	rm -f *.exe $(OBJDIR)/*.o $(ASMDIR)/*.asm $(ASMDIR)/*.S ./*.map ./*.out ./*.bin

#==================================================
# Implicit Targets
#==================================================
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<

project.exe: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

$(ASMDIR)/%.S: $(SRCDIR)/%.c $(DEPS)
	$(CC) $(SFLAGS) $< -o $@

$(ASMDIR)/%.asm: $(SRCDIR)/%.c $(DEPS)
	$(CC) $(SFLAGS) $< -o $@
