SRCDIR = src
BUILDDIR = bin
PRODDIR = prod
OBJDIR = obj
CLANG_FORMAT = .clang-format

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

.PHONY: clean run all build format help $(TARGET) bin_dir b_prod r_prod

help:
	@echo "---- RTS-Minesweeper Help ----"
	@echo ""
	@echo "Use: make <command>"
	@echo ""
	@echo "Available commands:"
	@echo "    help:      This help message."
	@echo "    build:     Build the game into $(BUILDDIR) ($(TARGET))."
	@echo "    run:       Build and RUN the game."
	@echo "    b_prod:    Build game for production (with optimizations)."
	@echo "    r_prod:    Build and RUN game for production (with optimizations)."
	@echo "    format:    Format all the .c and .h files in the $(SRCDIR) directory."
	@echo "    bin_dir:   Create the directory $(BUILDDIR)."
	@echo "    clean:     Clean the $(BUILDDIR) directory of all binaries."

run: $(TARGET)
ifeq ($(detected_OS), Windows)
	.\$(BUILDDIR)\$(TARGET)
else
	./$(BUILDDIR)/$(TARGET)
endif

all: $(TARGET)

build: $(TARGET)

b_prod: $(SRCDIR)/main.c
	mkdir -p $(PRODDIR)
	$(CC) $(SRCDIR)/main.c $(DEPS) -o $(PRODDIR)/$(TARGET) $(C_PROD_FLAGS)

r_prod: b_prod
ifeq ($(detected_OS), Windows)
	.\$(PRODDIR)\$(TARGET)
else
	./$(PRODDIR)/$(TARGET)
endif


$(TARGET): $(SRCDIR)/main.c bin_dir
	$(CC) $(SRCDIR)/main.c $(DEPS) -o $(BUILDDIR)/$(TARGET) $(CFLAGS) 

bin_dir:
	mkdir -p $(BUILDDIR)

format:
ifeq (, $(shell which clang-format))
	@echo "No clang-format command installed. Please install clangd or clang."
else
	find $(SRCDIR) -iname "*.h" -o -iname "*.c" | xargs clang-format -i -style=file:"$(CLANG_FORMAT)"
endif

clean:
	rm -rf $(BUILDDIR)
	mkdir -p $(BUILDDIR)
