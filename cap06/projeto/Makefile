CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99
RAYLIB_INC = -I./raylib/include
RAYLIB_LIB = -L./raylib/lib -lraylib -lGL -lX11 -lm -lpthread -ldl -lrt

BIN_DIR = bin
# Nome da pasta conforme o seu comando tree
PROJECTS = 6.1
EXECS = $(addprefix $(BIN_DIR)/, $(PROJECTS))

all: $(BIN_DIR) $(EXECS)

$(BIN_DIR):
	@mkdir -p $@

# Compila o main.c da pasta 6.1
$(BIN_DIR)/%: %/main.c
	@$(CC) $(CFLAGS) $^ $(RAYLIB_INC) $(RAYLIB_LIB) -o $@

clean:
	@rm -rf $(BIN_DIR)

.PHONY: all clean
