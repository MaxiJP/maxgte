all: main

CC=gcc
CFLAGS=-lSDL3 -lSDL3_ttf
OUTPUT_FILE=maxgte

main:
	$(CC) $(CFLAGS) -o $(OUTPUT_FILE) main.c
