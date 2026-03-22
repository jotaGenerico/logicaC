CC = gcc
CFLAGS = -O1 -Wall -Wextra -Wno-unused-parameter -pedantic-errors -std=c99 -Wno-missing-braces
RAYLIB_INC = -I./raylib/include
RAYLIB_LIB = -L./raylib/lib -lraylib -lGL -lX11 -lm -lpthread -ldl -lrt

BIN_DIR = bin
PROJECTS = bolinha olhinhos pong
EXECS = $(addprefix $(BIN_DIR)/, $(PROJECTS))

all: $(BIN_DIR) $(EXECS)

$(BIN_DIR):
	@mkdir -p $@

$(BIN_DIR)/bolinha: bolinha/*.c
	@$(CC) $(CFLAGS) -I./bolinha/include $^ $(RAYLIB_INC) $(RAYLIB_LIB) -o $@

$(BIN_DIR)/olhinhos: olhinhos/*.c
	@$(CC) $(CFLAGS) -I./olhinhos/include $^ $(RAYLIB_INC) $(RAYLIB_LIB) -o $@

$(BIN_DIR)/pong: pong/*.c
	@$(CC) $(CFLAGS) -I./pong/include $^ $(RAYLIB_INC) $(RAYLIB_LIB) -o $@

clean:
	@rm -rf $(BIN_DIR)

.PHONY: all clean
