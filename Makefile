SRCDIR = src
BUILDDIR = bin
OBJDIR = obj

ifeq ($(OS),Windows_NT)
    detected_OS := Windows
	CC = gcc
				
	CFLAGS = -Wall -Wshadow -Wextra -g -std=c99 -Wno-missing-braces -I include/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm
	C_PROD_FLAGS = -O3 -std=c99 -I include/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm
	TARGET = minesweeper-rts.exe
else
    detected_OS := $(shell uname)
	CC = gcc
	CFLAGS = -Wall -std=c99 -lm -lraylib -lpthread -ldl -lX11 -lrt -Wall -Wshadow -Wextra -Wno-missing-braces -g
	C_PROD_FLAGS = -std=c99 -O3 -lraylib -lpthread -ldl -lX11 -lrt -lm
	TARGET = minesweeper-rts
endif


.PHONY: clean run all

run: $(TARGET)
ifeq ($(detected_OS), Windows)
	$(BUILDDIR)/$(TARGET).exe
else
	./$(BUILDDIR)/$(TARGET)
endif

all: $(TARGET)

$(TARGET): $(SRCDIR)/main.c
	$(CC) $(CFLAGS) $(SRCDIR)/main.c -o $(BUILDDIR)/$(TARGET)

