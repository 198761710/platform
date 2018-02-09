ARCH := arm-linux-
ARCH := /usr/bin/
CC := $(ARCH)g++
STRIP := $(ARCH)strip
CFLAGS := -Ijson
CFLAGS += -Icgicc
CFLAGS += -Ibasic
CFLAGS += -Isocket
CFLAGS += -Iservice 
CFLAGS += -Ioperator
CFLAGS += -Ijson/rapidjson

JSON_CPP    := $(wildcard json/*.cpp)
CGICC_CPP   := $(wildcard cgicc/*.cpp)
BASIC_CPP   := $(wildcard basic/*.cpp)
SOCKET_SRC  := $(wildcard socket/*.c)
SOCKET_CPP  := $(wildcard socket/*.cpp)
SERVICE_CPP := $(wildcard service/*.cpp)
OPERATOR_CPP:= $(wildcard operator/*.cpp)

JSON_OBJ	:= $(patsubst %.cpp, %.o, $(JSON_CPP))
CGICC_OBJ	:= $(patsubst %.cpp, %.o, $(CGICC_CPP))
BASIC_OBJ   := $(patsubst %.cpp, %.o, $(BASIC_CPP))
SOCKET_OBJ  := $(patsubst %.c  , %.o, $(SOCKET_SRC))
SOCKET_OBJ  += $(patsubst %.cpp, %.o, $(SOCKET_CPP))
SERVICE_OBJ := $(patsubst %.cpp, %.o, $(SERVICE_CPP))
OPERATOR_OBJ:= $(patsubst %.cpp, %.o, $(OPERATOR_CPP))

OBJ := $(JSON_OBJ)
OBJ += $(CGICC_OBJ)
OBJ += $(BASIC_OBJ)
OBJ += $(SOCKET_OBJ)
OBJ += $(SERVICE_OBJ)
OBJ += $(OPERATOR_OBJ)

lTARGETS := service/service.a
lTARGETS += json/json.a
lTARGETS += cgicc/cgicc.a
lTARGETS += basic/basic.a
lTARGETS += socket/socket.a
lTARGETS += operator/operator.a

xTARGETS := bin/unix-udp-client.exe 
xTARGETS += bin/unix-udp-server.exe
xTARGETS += bin/unix-udp-connect.exe
xTARGETS += bin/basicservice.exe
xTARGETS += bin/basicconfig.exe
xTARGETS += bin/json.exe
xTARGETS += bin/packet.exe
xTARGETS += bin/basic.exe
xTARGETS += bin/testcgi.exe
xTARGETS += bin/varoperator.exe

target:  $(xTARGETS)
	@$(STRIP) $+
	@ls -shv $(xTARGETS)
	@rm -rf ztest/*.o

bin/cgi.exe: ztest/cgi.o $(lTARGETS)
	@$(CC) $+ -o $@ 
bin/basic.exe: ztest/basic.o $(lTARGETS)
	@$(CC) $+ -o $@ 
bin/packet.exe: ztest/packet.o $(lTARGETS)
	@$(CC) $+ -o $@ 
bin/basicservice.exe: ztest/basicservice.o $(lTARGETS)
	@$(CC) $+ -o $@ 
bin/basicconfig.exe: ztest/basicconfig.o $(lTARGETS)
	@$(CC) $+ -o $@ 
bin/unix-udp-client.exe: ztest/unix-udp-client.o $(lTARGETS)
	@$(CC) $+ -o $@ 
bin/unix-udp-connect.exe: ztest/unix-udp-connect.o $(lTARGETS)
	@$(CC) $+ -o $@ 
bin/unix-udp-server.exe: ztest/unix-udp-server.o $(lTARGETS)
	@$(CC) $+ -o $@
bin/json.exe: ztest/json.o $(lTARGETS)
	@$(CC) $+ -o $@
bin/testcgi.exe: ztest/testcgi.o $(lTARGETS)
	@$(CC) $+ -o $@
bin/varoperator.exe: ztest/varoperator.o $(lTARGETS)
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
operator/operator.a: $(OPERATOR_OBJ)
	@$(AR) -rc $@ $+

.c.o:
	@echo $(CC) $*.c -o $*.o
	@$(CC) $(CFLAGS) $*.c -c -o $*.o
.cpp.o:
	@echo $(CC) $*.cpp -o $*.o
	@$(CC) $(CFLAGS) $*.cpp -c -o $*.o

clean:
	@rm -rfv */*.o bin/*.exe
