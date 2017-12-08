ARCH := /usr/bin/
ARCH := arm-linux-
CC := $(ARCH)g++
STRIP := $(ARCH)strip
CFLAGS := -Ijson
CFLAGS += -Icgicc
CFLAGS += -Ibasic
CFLAGS += -Isocket
CFLAGS += -Iservice 
CFLAGS += -Ijson/rapidjson

JSON_CPP    := $(wildcard json/*.cpp)
CGICC_CPP   := $(wildcard cgicc/*.cpp)
BASIC_CPP   := $(wildcard basic/*.cpp)
SOCKET_SRC  := $(wildcard socket/*.c)
SOCKET_CPP  := $(wildcard socket/*.cpp)
SERVICE_CPP := $(wildcard service/*.cpp)

JSON_OBJ	:= $(patsubst %.cpp, %.o, $(JSON_CPP))
CGICC_OBJ	:= $(patsubst %.cpp, %.o, $(CGICC_CPP))
BASIC_OBJ   := $(patsubst %.cpp, %.o, $(BASIC_CPP))
SOCKET_OBJ  := $(patsubst %.c  , %.o, $(SOCKET_SRC))
SOCKET_OBJ  += $(patsubst %.cpp, %.o, $(SOCKET_CPP))
SERVICE_OBJ := $(patsubst %.cpp, %.o, $(SERVICE_CPP))

OBJ := $(JSON_OBJ)
OBJ += $(CGICC_OBJ)
OBJ += $(BASIC_OBJ)
OBJ += $(SOCKET_OBJ)
OBJ += $(SERVICE_OBJ)

lTARGETS := service/service.a
lTARGETS += json/json.a
lTARGETS += cgicc/cgicc.a
lTARGETS += basic/basic.a
lTARGETS += socket/socket.a

xTARGETS := bin/unix-udp-client.exe 
xTARGETS += bin/unix-udp-server.exe
xTARGETS += bin/unix-udp-connect.exe
xTARGETS += bin/service.exe
xTARGETS += bin/json.exe
xTARGETS += bin/packet.exe
xTARGETS += bin/basic.exe

target:  $(xTARGETS)
	@$(STRIP) $+
	@ls -shv $(xTARGETS)
	@rm -rf test/*.o

bin/basic.exe: test/basic.o $(lTARGETS)
	@$(CC) $+ -o $@ 
bin/packet.exe: test/packet.o $(lTARGETS)
	@$(CC) $+ -o $@ 
bin/service.exe: test/service.o $(lTARGETS)
	$(CC) $+ -o $@ 
bin/unix-udp-client.exe: test/unix-udp-client.o $(lTARGETS)
	@$(CC) $+ -o $@ 
bin/unix-udp-connect.exe: test/unix-udp-connect.o $(lTARGETS)
	@$(CC) $+ -o $@ 
bin/unix-udp-server.exe: test/unix-udp-server.o $(lTARGETS)
	@$(CC) $+ -o $@
bin/json.exe: test/json.o $(lTARGETS)
	@$(CC) $+ -o $@

json/json.a: $(JSON_OBJ)
	@$(AR) -rc $@ $+
cgicc/cgicc.a: $(CGICC_OBJ)
	@$(AR) -rc $@ $+
basic/basic.a: $(BASIC_OBJ)
	@$(AR) -rc $@ $+
socket/socket.a: $(SOCKET_OBJ)
	@$(AR) -rc $@ $+
service/service.a: $(SERVICE_OBJ)
	@$(AR) -rc $@ $+

.c.o:
	@echo $(CC) $*.c -o $*.o
	@$(CC) $(CFLAGS) $*.c -c -o $*.o
.cpp.o:
	@echo $(CC) $*.cpp -o $*.o
	@$(CC) $(CFLAGS) $*.cpp -c -o $*.o

clean:
	@rm -rfv */*.o bin/*.exe
