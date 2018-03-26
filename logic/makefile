ARCH := /usr/bin/
ARCH := arm-linux-
CC := $(ARCH)g++
STRIP := $(ARCH)strip
CFLAGS := -Ijson
CFLAGS += -Icgicc
CFLAGS += -Ibasic
CFLAGS += -Isocket
CFLAGS += -Imanager
CFLAGS += -Iservice 
CFLAGS += -Ioperator
CFLAGS += -Ijson/rapidjson

OBJ	:= $(patsubst %.c, %.o, $(wildcard [a-y]*/*.c))
OBJ	+= $(patsubst %.cpp, %.o, $(wildcard [a-y]*/*.cpp))
LIB := lib.a

TARGETS := bin/unix-udp-client.exe 
TARGETS += bin/unix-udp-server.exe
TARGETS += bin/unix-udp-connect.exe
TARGETS += bin/basicservice.exe
TARGETS += bin/basicconfig.exe
TARGETS += bin/json.exe
TARGETS += bin/packet.exe
TARGETS += bin/basic.exe
TARGETS += bin/testcgi.exe
TARGETS += bin/varoperator.exe

target:  $(TARGETS)
	@$(STRIP) $+
	@ls -1shv $(TARGETS)

bin/cgi.exe: ztest/cgi.o $(LIB)
	@$(CC) $+ -o $@ 
bin/basic.exe: ztest/basic.o $(LIB)
	@$(CC) $+ -o $@ 
bin/packet.exe: ztest/packet.o $(LIB)
	@$(CC) $+ -o $@ 
bin/basicservice.exe: ztest/basicservice.o $(LIB)
	@$(CC) $+ -o $@ 
bin/basicconfig.exe: ztest/basicconfig.o $(LIB)
	@$(CC) $+ -o $@ 
bin/unix-udp-client.exe: ztest/unix-udp-client.o $(LIB) 
	@$(CC) $+ -o $@ 
bin/unix-udp-connect.exe: ztest/unix-udp-connect.o $(LIB)
	@$(CC) $+ -o $@ 
bin/unix-udp-server.exe: ztest/unix-udp-server.o $(LIB)
	@$(CC) $+ -o $@
bin/json.exe: ztest/json.o $(LIB)
	@$(CC) $+ -o $@
bin/testcgi.exe: ztest/testcgi.o $(LIB)
	@$(CC) $+ -o $@
bin/varoperator.exe: ztest/varoperator.o $(LIB)
	@$(CC) $+ -o $@

lib.a: $(OBJ)
	@$(AR) -rc $@ $+
.c.o:
	@echo $(CC) -c $*.c -o $@
	@$(CC) $(CFLAGS) $*.c -c -o $@
.cpp.o:
	@echo $(CC) -c $*.cpp -o $@
	@$(CC) $(CFLAGS) $*.cpp -c -o $@

clean:
	@rm -rfv $(OBJ) $(LIB) $(TARGETS) 
