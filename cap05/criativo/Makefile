CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99
RAYLIB_INC = -I./raylib/include
RAYLIB_LIB = -L./raylib/lib -lraylib -lGL -lX11 -lm -lpthread -ldl -lrt

BIN_DIR = bin
EXERCISES = exc5.1 exc5.2 exc5.1mouse exc5.2mouse
EXECS = $(addprefix $(BIN_DIR)/, $(EXERCISES))

all: $(BIN_DIR) $(EXECS)

$(BIN_DIR):
	@mkdir -p $@

$(BIN_DIR)/%: %/main.c
	@$(CC) $(CFLAGS) $^ $(RAYLIB_INC) $(RAYLIB_LIB) -o $@

clean:
	@rm -rf $(BIN_DIR)

.PHONY: all clean
