# **************************************************************************** #
#                                 Makefile (Raylib Projects)                   #
# **************************************************************************** #

# ============================================================================ #
# Configurações de Compilação
# ============================================================================ #

CC = gcc
# Flags de compilação: Ativar todas as checagens e tratar avisos como erros.
# Esta linha garante a conformidade com as boas práticas (como no ambiente 42),
# mas sem a referência explícita.
CFLAGS = -Wall -Wextra -Werror -std=c99

# ============================================================================ #
# Caminhos e Dependências (Raylib)
# ============================================================================ #

# Caminho dos includes do Raylib (pasta 'raylib/include' local)
RAYLIB_INC = -I./raylib/include

# Bibliotecas Raylib e dependências de sistema para janelas gráficas (OpenGL/X11).
# O uso de -lGL -lX11 é padrão para projetos Raylib em Linux.
RAYLIB_LIB = -L./raylib/lib -lraylib -lGL -lX11 -lm -lpthread -ldl

# Diretório de saída dos executáveis
BIN_DIR = bin

# Lista dos nomes dos executáveis (Mantenha esta lista atualizada)
EXERCISES = exc2.1 exc2.2 exc2.3 exc2.4
EXECS = $(addprefix $(BIN_DIR)/, $(EXERCISES))

# ============================================================================ #
# Regras de Compilação
# ============================================================================ #

# 🎯 Regra principal: Cria o diretório bin/ e compila todos os executáveis
all: $(BIN_DIR) $(EXECS)

# Regra para criar o diretório bin/
$(BIN_DIR):
	@mkdir -p $@

# 🔨 Regra de Compilação Genérica
# Compila o arquivo 'exc3.x/main.c' para criar o binário 'bin/exc3.x'
$(BIN_DIR)/%: %/main.c
	@echo "Compilando $* -> $(BIN_DIR)/$*..."
	# $(CC) $(CFLAGS) [fonte] [includes] [bibliotecas] -o [saída]
	$(CC) $(CFLAGS) $^ $(RAYLIB_INC) $(RAYLIB_LIB) -o $@
	@echo "Executável criado: $@"

# ============================================================================ #
# Regras de Limpeza
# ============================================================================ #

# Limpa apenas os binários
clean:
	@echo "Limpando executáveis..."
	@rm -rf $(BIN_DIR)
	@echo "Limpeza de binários concluída."

# Limpeza total (igual a clean neste projeto, pois não há objetos .o)
fclean: clean
	@echo "Limpeza total concluída."

re: fclean all

# Regras Phony
.PHONY: all clean fclean re $(BIN_DIR)
