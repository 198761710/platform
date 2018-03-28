ARCH := arm-linux-
ARCH := powerpc-e300c3-linux-gnu-
ARCH := /usr/bin/

CC := $(ARCH)g++
AR := $(ARCH)ar
ST := $(ARCH)strip

CFLAGS := -Ijson
CFLAGS += -Icgicc
CFLAGS += -Ibasic
CFLAGS += -Isocket
CFLAGS += -Imanager
CFLAGS += -Iservice 
CFLAGS += -Ijson/rapidjson

OBJ	:= $(patsubst %.c, %.o, $(wildcard [a-y]*/*.c))
OBJ	+= $(patsubst %.cpp, %.o, $(wildcard [a-y]*/*.cpp))
LIB := bin/lib.a

TARGET := bin/client.exe 
TARGET += bin/server.exe
TARGET += bin/connect.exe
TARGET += bin/json.exe
TARGET += bin/basic.exe
TARGET += bin/testcgi.exe
TARGET += bin/basicservice.exe

all: $(TARGET)
	@$(ST) $+
	@ls -1shv bin/*

.c.o:
	@echo $(CC) -c $*.c -o $@
	@$(CC) $(CFLAGS) $*.c -c -o $@
.cpp.o:
	@echo $(CC) -c $*.cpp -o $@
	@$(CC) $(CFLAGS) $*.cpp -c -o $@
bin/lib.a: $(OBJ)
	@$(AR) -rc $@ $+

bin/cgi.exe: ztest/cgi.o $(LIB)
	@$(CC) $+ -o $@ 
bin/basic.exe: ztest/basic.o $(LIB)
	@$(CC) $+ -o $@ 
bin/client.exe: ztest/client.o $(LIB) 
	@$(CC) $+ -o $@ 
bin/connect.exe: ztest/connect.o $(LIB)
	@$(CC) $+ -o $@ 
bin/server.exe: ztest/server.o $(LIB)
	@$(CC) $+ -o $@
bin/json.exe: ztest/json.o $(LIB)
	@$(CC) $+ -o $@
bin/testcgi.exe: ztest/testcgi.o $(LIB)
	@$(CC) $+ -o $@
bin/basicservice.exe: ztest/basicservice.o $(LIB)
	@$(CC) $+ -o $@ 

clean:
	@rm -rfv $(OBJ) $(LIB) $(TARGET) ztest/*.o
