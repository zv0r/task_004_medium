CC := gcc
CFLAGS := -g -std=c11 -Werror -Wall -Wextra
BIN_DIR := ../bin

all: build

build: find_duplicates cryptography ascii_sort

find_duplicates:
	${CC} ${CFLAGS} -o ${BIN_DIR}/find_duplicates find_duplicates.c misc.c

cryptography:
	${CC} ${CFLAGS} -o ${BIN_DIR}/cryptography cryptography.c misc.c

ascii_sort:
