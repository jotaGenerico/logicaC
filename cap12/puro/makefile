# Nome do executável
NAME = programa

# Arquivos
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
INC = -I.

# Flags de compilação
CFLAGS = -Wall -Wextra -Werror $(INC)

# Comandos
CC = gcc
RM = rm -f

# Regras
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $@

clean:
	$(RM) $(OBJ) $(NAME)

re: clean all

.PHONY: all clean re
