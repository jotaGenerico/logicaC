CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99
# Aponta para a pasta raylib que está na raiz do cap06/criativo
RAYLIB_INC = -I./raylib/include
RAYLIB_LIB = -L./raylib/lib -lraylib -lGL -lX11 -lm -lpthread -ldl -lrt

BIN_DIR = bin
# Lista atualizada para o Capítulo 6
EXERCISES = exc6.1 exc6.2 exc6.3 exc6.4 exc6.5
EXECS = $(addprefix $(BIN_DIR)/, $(EXERCISES))

all: $(BIN_DIR) $(EXECS)

$(BIN_DIR):
	@mkdir -p $@

# Compila cada main.c para seu respectivo binário em bin/
$(BIN_DIR)/%: %/main.c
	@$(CC) $(CFLAGS) $^ $(RAYLIB_INC) $(RAYLIB_LIB) -o $@

clean:
	@rm -rf $(BIN_DIR)

.PHONY: all clean
