#将当前目录下的.c文件分别编译成可执行文件
.PHONY: all  clean
SRC=$(wildcard *.c)
BIN=$(SRC:%.c=%)
 
CC=gcc
CFLAGS=-Wall -g -c
 
all:$(BIN)

clean:
	rm  $(BIN)
