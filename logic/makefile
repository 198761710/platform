ARCH := /usr/bin/
ARCH := arm-linux-
CC := $(ARCH)g++
STRIP := $(ARCH)strip
CFLAGS := -Iservice -Isocket -Ijson -Ijson/rapidjson -Icgicc
CFLAGS += -Ibasic
SRC := $(wildcard socket/*.c)
CPP := $(wildcard json/*.cpp)
CPP += $(wildcard socket/*.cpp)
CPP += $(wildcard service/*.cpp)
CPP += $(wildcard basic/*.cpp)
OBJ := $(patsubst %.c, %.o, $(SRC))
OBJ += $(patsubst %.cpp, %.o, $(CPP))
TARGETS := bin/unix-udp-client.exe 
TARGETS += bin/unix-udp-server.exe
TARGETS += bin/unix-udp-connect.exe
TARGETS += bin/service.exe
TARGETS += bin/json.exe
TARGETS += bin/packet.exe
TARGETS += bin/basic.exe

target: $(TARGETS)
	@$(STRIP) $(TARGETS)
	@ls -lhs $(TARGETS)

bin/basic.exe: $(OBJ) test/basic.o
	@$(CC) $+ -o $@
bin/packet.exe: $(OBJ) test/packet.o
	@$(CC) $+ -o $@
bin/service.exe: $(OBJ) test/service.o
	@$(CC)  $+ -o $@
bin/unix-udp-client.exe: $(OBJ) test/unix-udp-client.o
	@$(CC)  $+ -o $@
bin/unix-udp-connect.exe: $(OBJ) test/unix-udp-connect.o
	@$(CC)  $+ -o $@
bin/unix-udp-server.exe: $(OBJ) test/unix-udp-server.o
	@$(CC)  $+ -o $@
bin/json.exe: $(OBJ) test/json.o
	@$(CC) $+ -o $@
.c.o:
	@echo $(CC) $*.c -o $*.o
	@$(CC) $(CFLAGS) $*.c -c -o $*.o
.cpp.o:
	@echo $(CC) $*.cpp -o $*.o
	@$(CC) $(CFLAGS) $*.cpp -c -o $*.o

clean:
	@rm -rfv */*.o bin/*.exe
