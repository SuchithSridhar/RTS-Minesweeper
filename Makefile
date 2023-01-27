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

DEPS_GRAPHICS = graphics/gameplay.c graphics/gui.c graphics/start.c graphics/gameplay/board.c
DEPS_GAME_FUNCTIONS = game_functions/board_functions.c

DEPS__ = $(DEPS_GRAPHICS) $(DEPS_GAME_FUNCTIONS)
DEPS = $(foreach dir, $(DEPS__), $(addprefix $(SRCDIR)/, $(dir)))

.PHONY: clean run all

run: $(TARGET)
ifeq ($(detected_OS), Windows)
	.\$(BUILDDIR)\$(TARGET)
else
	./$(BUILDDIR)/$(TARGET)
endif

all: $(TARGET)

$(TARGET): $(SRCDIR)/main.c bin_dir
	$(CC) $(SRCDIR)/main.c $(DEPS) -o $(BUILDDIR)/$(TARGET) $(CFLAGS) 

bin_dir:
	mkdir $(BUILDDIR)

