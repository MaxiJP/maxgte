all: main

CC=gcc
CFLAGS=
OUTPUT_FILE=maxgte

main:
	$(CC) $(CFLAGS) -o $(OUTPUT_FILE) main.c
