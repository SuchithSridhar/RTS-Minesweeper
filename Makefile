SRCDIR = src
BUILDDIR = bin
PRODDIR = prod
OBJDIR = obj
DOCS_DIR = docs
CLANG_FORMAT = .clang-format
mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
PROJ_DIR = $(dir $(mkfile_path))

# Normal Color variables C_BLACK=\033[30m
C_RED=\033[31m
C_GREEN=\033[32m
C_YELLOW=\033[33m
C_BLUE=\033[34m
C_PURPLE=\033[35m
C_CYAN=\033[36m
C_WHITE=\033[37m
C_GRAY=\033[90m

# Bright Color variables
C_RED_B=\033[91m
C_GREEN_B=\033[92m
C_YELLOW_B=\033[93m
C_BLUE_B=\033[94m
C_PURPLE_B=\033[95m
C_CYAN_B=\033[96m

# Color reset character
C_RESET=\033[0m

ifeq ($(OS),Windows_NT)
	detected_OS := Windows
	CC = gcc
				
	CFLAGS = -Wall -Wshadow -Wextra -g -std=c99 -Wno-missing-braces -I include/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm
	C_PROD_FLAGS = -O3 -std=c99 -I include/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm
	TARGET = minesweeper-rts.exe
	OPEN = start
else
	detected_OS := $(shell uname)
	CC = gcc
	CFLAGS = -Wall -std=c99 -lm -lraylib -lpthread -ldl -lX11 -lrt -Wall -Wshadow -Wextra -Wno-missing-braces -g
	C_PROD_FLAGS = -std=c99 -O3 -lraylib -lpthread -ldl -lX11 -lrt -lm
	TARGET = minesweeper-rts
        OPEN = xdg-open
endif

DEPS_GRAPHICS = graphics/gameplay.c graphics/gui.c graphics/start.c graphics/gameplay/board.c
DEPS_GAME_FUNCTIONS = game_functions/board_functions.c

DEPS__ = $(DEPS_GRAPHICS) $(DEPS_GAME_FUNCTIONS)
DEPS = $(foreach dir, $(DEPS__), $(addprefix $(SRCDIR)/, $(dir)))

.PHONY: clean run all build format help $(TARGET) bin_dir b_prod r_prod gen_docs docs

help:
	@printf " ---- RTS-Minesweeper Help ---- \n"
	@printf "\n"
	@printf "Use: make $(C_BLUE)<command>$(C_RESET)\n"
	@printf "\n"
	@printf "Available commands:\n"
	@printf "    $(C_GREEN)help:$(C_RESET)      This help message.\n"
	@printf "    $(C_GREEN)build:$(C_RESET)     Build the game into $(BUILDDIR) $(C_BLUE)($(TARGET))$(C_RESET).\n"
	@printf "    $(C_GREEN)run:$(C_RESET)       Build and RUN the game.\n"
	@printf "    $(C_GREEN)docs:$(C_RESET)      Open the documentation for the project.\n"
	@printf "    $(C_GREEN)b_prod:$(C_RESET)    Build game for production (with optimizations).\n"
	@printf "    $(C_GREEN)r_prod:$(C_RESET)    Build and RUN game for production (with optimizations).\n"
	@printf "    $(C_GREEN)format:$(C_RESET)    Format all the .c and .h files in the $(SRCDIR) directory.\n"
	@printf "    $(C_GREEN)gen_docs:$(C_RESET)  Generate documentation for the project.\n"
	@printf "    $(C_GREEN)bin_dir:$(C_RESET)   Create the directory $(BUILDDIR).\n"
	@printf "    $(C_GREEN)clean:$(C_RESET)     Clean the $(BUILDDIR) directory of all binaries.\n"
	@printf "\n"
	@printf "Using Makefile: $(mkfile_path)\n"

run: $(TARGET)
ifeq ($(detected_OS), Windows)
	.\$(BUILDDIR)\$(TARGET)
else
	./$(BUILDDIR)/$(TARGET)
endif

all: $(TARGET)

build: $(TARGET)

b_prod: $(SRCDIR)/main.c
	@printf "== Generating production binary of$(C_BLUE) $(TARGET) $(C_RESET)==\n"
	mkdir -p $(PRODDIR)
	$(CC) $(SRCDIR)/main.c $(DEPS) -o $(PRODDIR)/$(TARGET) $(C_PROD_FLAGS)

r_prod: b_prod
ifeq ($(detected_OS), Windows)
	.\$(PRODDIR)\$(TARGET)
else
	./$(PRODDIR)/$(TARGET)
endif

docs:
	$(OPEN) file:///$(PROJ_DIR)$(DOCS_DIR)/html/index.html

gen_docs:
ifeq (, $(shell which doxygen))
	@printf "$(C_RED)doxygen not installed. Please install doxygen to generate documentation.$(C_RESET)\n"
else
	doxygen $(DOCS_DIR)/Doxyfile
	@printf "\n$(C_GREEN)Documentation generated for the project.$(C_RESET)\n"
	@printf "\nRun: \`$(C_BLUE)make docs$(C_RESET)\` to view the generated docs.$(C_RESET)\n"
endif


$(TARGET): $(SRCDIR)/main.c bin_dir
	$(CC) $(SRCDIR)/main.c $(DEPS) -o $(BUILDDIR)/$(TARGET) $(CFLAGS) 

bin_dir:
	mkdir -p $(BUILDDIR)

format:
ifeq (, $(shell which clang-format))
	@printf "$(C_RED)No clang-format command installed. Please install clangd or clang.$(C_RESET)\n"
else
	find $(SRCDIR) -iname "*.h" -o -iname "*.c" | xargs clang-format -i -style=file:"$(CLANG_FORMAT)"
endif

clean:
	@printf "Cleaning the build directory..."
	rm -rf $(BUILDDIR)
	mkdir -p $(BUILDDIR)
