ARCH:=/usr/bin/
CC:=$(ARCH)g++
CFLAGS:= -Isocket -Ijson -Ijson/rapidjson -Icgicc
SRC:= socket/unix-udp.cpp json/json.cpp
TARGETS:= bin/unix-udp-client.exe 
TARGETS+= bin/unix-udp-server.exe
TARGETS+= bin/unix-udp-connect.exe
TARGETS+= bin/json.exe

target: $(TARGETS)

bin/unix-udp-client.exe: $(SRC) test/unix-udp-client.cpp
	@echo $(CC) $+ -o $@
	@$(CC) $(CFLAGS) $+ -o $@

bin/unix-udp-connect.exe: $(SRC) test/unix-udp-connect.cpp
	@echo $(CC) $+ -o $@
	@$(CC) $(CFLAGS) $+ -o $@

bin/unix-udp-server.exe: $(SRC) test/unix-udp-server.cpp
	@echo $(CC) $+ -o $@
	@$(CC) $(CFLAGS) $+ -o $@

bin/json.exe: $(SRC) test/json.cpp
	@echo $(CC) $+ -o $@
	@$(CC) $(CFLAGS) $+ -o $@

clean:
	@rm bin/*.exe
