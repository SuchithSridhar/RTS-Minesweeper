# Makefile for RTS-Minesweeper

# Variables
SRC_DIR = src
BUILD_DIR = bin
PROD_DIR = prod
OBJ_DIR = obj
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
	DEV_TARGET_PATH = .\$(BUILD_DIR)\$(TARGET)
	PROD_TARGET_PATH = .\$(PROD_DIR)\$(TARGET)
	DOCS_INDEX = file://$(PROJ_DIR)$(DOCS_DIR)/html/index.html
	OPEN = explorer
else
	detected_OS := $(shell uname)
	CC = gcc
	CFLAGS = -Wall -std=c99 -lm -lraylib -lpthread -ldl -lX11 -lrt -Wall -Wshadow -Wextra -Wno-missing-braces -g
	C_PROD_FLAGS = -std=c99 -O3 -lraylib -lpthread -ldl -lX11 -lrt -lm
	TARGET = minesweeper-rts
	DEV_TARGET_PATH = ./$(BUILD_DIR)/$(TARGET)
	PROD_TARGET_PATH = ./$(PROD_DIR)/$(TARGET)
	DOCS_INDEX = file://$(PROJ_DIR)$(DOCS_DIR)/html/index.html
        OPEN = xdg-open
endif

DEPS_GRAPHICS = graphics/gameplay.c graphics/gui.c graphics/start.c graphics/gameplay/board.c 
DEPS_GAME_FUNCTIONS = game_functions/board_functions.c

DEPS__ = $(DEPS_GRAPHICS) $(DEPS_GAME_FUNCTIONS)
DEPS = $(foreach dir, $(DEPS__), $(addprefix $(SRC_DIR)/, $(dir)))

.PHONY: help build run docs clean b_dev r_dev debug mem_test format gen_docs bin_dir clean_dev

help:
	@printf " ---- RTS-Minesweeper Help ---- \n"
	@printf "\n"
	@printf "Use: make $(C_BLUE)<command>$(C_RESET)\n"
	@printf "\n"
	@printf "$(C_PURPLE)Available user commands:$(C_RESET)\n"
	@printf "    $(C_GREEN)help:$(C_RESET)      This help message.\n"
	@printf "    $(C_GREEN)build:$(C_RESET)     Build the game.\n"
	@printf "    $(C_GREEN)run:$(C_RESET)       Build and RUN the game.\n"
	@printf "    $(C_GREEN)docs:$(C_RESET)      Open the documentation for the project.\n"
	@printf "    $(C_GREEN)clean:$(C_RESET)     Clean the $(BUILD_DIR) directory of all binaries.\n"
	@printf "\n"
	@printf "$(C_PURPLE)Available dev commands:$(C_RESET)\n"
	@printf "    $(C_GREEN)b_dev:$(C_RESET)     Build game for dev testing (with debug symbols).\n"
	@printf "    $(C_GREEN)r_dev:$(C_RESET)     Build and RUN game for dev testing (with debug symbols).\n"
	@printf "    $(C_GREEN)debug:$(C_RESET)     Build and run $(C_BLUE)gdb$(C_RESET) on application.\n"
	@printf "    $(C_GREEN)mem_test:$(C_RESET)  Build and run $(C_BLUE)valgrind$(C_RESET) on application.\n"
	@printf "    $(C_GREEN)format:$(C_RESET)    Format all the .c and .h files in the $(SRC_DIR) directory.\n"
	@printf "    $(C_GREEN)gen_docs:$(C_RESET)  Generate documentation for the project.\n"
	@printf "    $(C_GREEN)bin_dir:$(C_RESET)   Create the directory $(BUILD_DIR).\n"
	@printf "    $(C_GREEN)prod_dir:$(C_RESET)  Create the production dir $(PROD_DIR).\n"
	@printf "    $(C_GREEN)clean_dev:$(C_RESET) Clean the $(C_BLUE)$(BUILD_DIR)$(C_RESET) directory.\n"
	@printf "\n"
	@printf "Using Makefile: $(mkfile_path)\n"

build: $(SRC_DIR)/main.c prod_dir
	@printf "== Generating production binary of$(C_BLUE) $(TARGET) $(C_RESET)==\n"
	$(CC) $(SRC_DIR)/main.c $(DEPS) -o $(PROD_TARGET_PATH) $(C_PROD_FLAGS)

run: build
	$(PROD_TARGET_PATH)

docs:
	$(OPEN) $(DOCS_INDEX) || true

clean:
	@printf "Cleaning the production directory..."
	rm -rf $(PROD_DIR)
	mkdir -p $(PROD_DIR)

b_dev: $(SRC_DIR)/main.c bin_dir
	$(CC) $(SRC_DIR)/main.c $(DEPS) -o $(DEV_TARGET_PATH) $(CFLAGS) 

r_dev: b_dev
	$(DEV_TARGET_PATH)

debug: b_dev
	gdb $(DEV_TARGET_PATH)

mem_test:
	valgrind -s --leak-check=full --show-leak-kinds=all $(DEV_TARGET_PATH)

format:
	find $(SRC_DIR) -iname "*.h" -o -iname "*.c" | xargs clang-format -i -style=file:"$(CLANG_FORMAT)"

gen_docs:
	doxygen $(DOCS_DIR)/Doxyfile
	@printf "\n$(C_GREEN)Documentation generated for the project.$(C_RESET)\n"
	@printf "\nRun: \`$(C_BLUE)make docs$(C_RESET)\` to view the generated docs.$(C_RESET)\n"

prod_dir:
	mkdir -p $(PROD_DIR)

bin_dir:
	mkdir -p $(BUILD_DIR)

clean_dev:
	@printf "Cleaning the build directory..."
	rm -rf $(BUILD_DIR)
	mkdir -p $(BUILD_DIR)

