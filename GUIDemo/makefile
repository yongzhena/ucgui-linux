########################################
#makefile
########################################
#****************************************************************************
# Cross complie path
#****************************************************************************
#CHAIN_ROOT=/home/yang/imax283/ctools/gcc-4.4.4-glibc-2.11.1-multilib-1.0/arm-fsl-linux-gnueabi/bin

#CROSS_COMPILE=$(CHAIN_ROOT)/arm-none-linux-gnueabi-
#CHAIN_ROOT= /home/yang/b503/ctools/gcc-linaro-arm-linux-gnueabihf-4.9-2014.09_linux/bin
#CROSS_COMPILE=$(CHAIN_ROOT)/arm-linux-gnueabihf-
#CROSS_COMPILE = 

CC     := $(CROSS_COMPILE)gcc
CXX    := $(CROSS_COMPILE)g++
AS     := $(CROSS_COMPILE)as
AR     := $(CROSS_COMPILE)ar 
LD     := $(CROSS_COMPILE)ld
RANLIB := $(CROSS_COMPILE)ranlib
OBJDUMP:= $(CROSS_COMPILE)objdump
OBJCOPY:= $(CROSS_COMPILE)objcopy
STRIP  := $(CROSS_COMPILE)strip

#编译指定子目录
SUBDIRS := 

define make_subdir
 @ for subdir in $(SUBDIRS) ; do \
 ( cd $$subdir && make $1) \
 done;
endef

#编译主程序
BINARY  := test
OBJ_DIR := 


CFLAGS= -std=c99 -Wall -g -I ../ucgui/GUI/Core -I ../ucgui/GUI/WM -I ../ucgui/GUI/Widget -I ../ucgui/GUI_X
LDSCRIPT= -lucgui -lm
LDFLAGS= -L./ 

SRC  = $(wildcard *.c)
DIR  = $(notdir $(SRC))
OBJS = $(patsubst %.c,$(OBJ_DIR)%.o,$(DIR))
#OBJS=  testdb.o
#CFLAGS=-std=c99
#@echo Building lib...
#$(call make_subdir)
.PHONY: clean lib
all:  prebuild  $(BINARY).out

prebuild:
	@echo Building app...

$(BINARY).out : $(OBJS)
	@echo Generating ...
	$(CC) -o $(BINARY).out $(OBJS) $(LDFLAGS) $(LDSCRIPT) 
	@echo OK!

$(OBJ_DIR)%.o : %.c
	$(CC) -c $(CFLAGS) $< -o  $@
	
lib:
	@echo Building lib...
	$(call make_subdir)
	
clean:
	rm -f $(OBJ_DIR)*.o
	@echo Removed!
