ARCH :=
CC := $(ARCH)g++
SRC := $(wildcard *.c)
SRC += $(wildcard *.cpp)

test.exe: $(SRC)
	$(CC) $+ -o $@ -DTEST_FILEOPERATOR

clean:
	rm *.exe *.o -rfv
