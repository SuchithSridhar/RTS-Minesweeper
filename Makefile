SRCDIR = src
BUILDDIR = bin
OBJDIR = obj

CC = gcc
CFLAGS = -Wall -std=c99 -lm -lraylib -lpthread -ldl -lX11 -lrt -Wall -Wshadow -Wextra
C_PROD_FLAGS = -std=c99 -O3 -lraylib -lpthread -ldl -lX11 -lrt -lm


TARGET = minesweeper-rts

.PHONY: clean run all

run: $(TARGET)
	./$(BUILDDIR)/$(TARGET)

all: $(TARGET)

$(TARGET): $(SRCDIR)/main.c
	$(CC) $(CFLAGS) $(SRCDIR)/main.c -o $(BUILDDIR)/$(TARGET)

