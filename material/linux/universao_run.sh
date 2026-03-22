#!/bin/bash

# ======================================================================
# Script de Gerenciamento Raylib Docker (Modelo UNIVERSAL)
#
# Uso: ./run.sh [build | <nome_do_exercicio> | fclean]
# Este modelo suporta TTY (scanf), PIPE, e execuções gráficas padrão.
# ======================================================================

# ======================================================================
# 🚨 CONFIGURAÇÃO DE VARIÁVEIS POR CAPÍTULO 🚨
# ======================================================================
IMAGEM="raylib-cap0X"           # 1. EDITE: Nome da imagem (Ex: raylib-cap01)
DIR="."                         # Contexto do build: diretório atual

# 2. EDITE: Lista de todos os executáveis, separados por pipe '|'
EXERCISES="olaRaylib|exc1.1|exc1.2|exc1.3"

# 3. Mapeamento de I/O: Associa o nome do exercício ao tipo de I/O necessário.
#    Tipos: TTY (scanf interativo), PIPE (echo |), GRAPHIC (padrão)
# 🚨 EXEMPLETO (Capítulo 1): Se todos usam scanf, defina todos como TTY.
declare -A EXERCISE_MODELS=(
    ["olaRaylib"]="TTY"
    ["exc1.1"]="TTY"
    ["exc1.2"]="TTY"
    ["exc1.3"]="TTY"
    # ["exc2.1"]="PIPE"   # Exemplo para Pipe
    # ["exc3.1"]="GRAPHIC" # Exemplo para Gráfico Padrão
)
# ======================================================================

COMANDO="$1"

# Verifica se o Docker está instalado
if ! command -v docker &> /dev/null
then
    echo "Erro: Docker não encontrado. Por favor, instale o Docker."
    exit 1
fi

# ======================================================================
# Ação: BUILD (Compilar o projeto)
# ======================================================================
if [ "$COMANDO" = "build" ]; then
    echo "Construindo a imagem Docker '$IMAGEM' e compilando o projeto..."

    make fclean > /dev/null 2>&1

    docker build -t $IMAGEM $DIR
    if [ $? -eq 0 ]; then
        echo "✅ Compilação do projeto no Docker concluída com sucesso. Imagem $IMAGEM criada."
    else
        echo "❌ Falha na compilação do projeto Docker. Verifique o Makefile e o Dockerfile."
        exit 1
    fi

# ======================================================================
# Ação: FCLEAN (Limpeza Profunda do Docker e Binários Locais)
# ======================================================================
elif [ "$COMANDO" = "fclean" ]; then
    echo "Executando limpeza profunda (fclean) do Docker..."

    docker rmi -f $IMAGEM 2>/dev/null
    docker system prune --force
    make fclean > /dev/null 2>&1

    echo "✅ Limpeza total concluída. O ambiente está limpo."

# ======================================================================
# Ação: RUN (Executar um exercício)
# ======================================================================
elif [[ "$COMANDO" =~ ^($EXERCISES)$ ]]; then

    BINARIO="./bin/$COMANDO"
    MODELO=${EXERCISE_MODELS[$COMANDO]}

    # 🚨 Determina as flags de I/O com base no mapeamento
    IO_FLAGS=""
    if [ "$MODELO" == "TTY" ]; then
        IO_FLAGS="-i -t" # Para scanf interativo
        echo "Iniciando execução TTY Interativa e Gráfica de '$COMANDO'..."
    elif [ "$MODELO" == "PIPE" ]; then
        IO_FLAGS="-i" # Para entrada via pipe (echo |)
        echo "Iniciando execução Pipe/Redirecionamento e Gráfica de '$COMANDO'..."
    elif [ "$MODELO" == "GRAPHIC" ]; then
        IO_FLAGS="" # Para execução padrão (mouse/teclado)
        echo "Iniciando execução Gráfica Padrão de '$COMANDO'..."
    else
        echo "❌ ERRO: Modelo de I/O '$MODELO' não definido para '$COMANDO'. Verifique EXERCISE_MODELS."
        exit 1
    fi

    # PASSO 1: Adiciona permissão temporária para acesso ao X Server
    xhost +local:docker 2>/dev/null

    # PASSO 2: Executa o contêiner, injetando as flags de I/O
    docker run --rm \
               $IO_FLAGS \
               --privileged \
               -e DISPLAY=$DISPLAY \
               -v /tmp/.X11-unix:/tmp/.X11-unix \
               $IMAGEM \
               $BINARIO

    EXIT_CODE=$?

    # PASSO 3: Revoga a permissão X11
    xhost -local:docker 2>/dev/null

    if [ $EXIT_CODE -ne 0 ]; then
        echo "❌ Ocorreu um erro na execução. (Código de saída: $EXIT_CODE)"
    else
        echo "Execução de '$COMANDO' finalizada."
    fi

# ======================================================================
# Ação: Ajuda/Erro
# ======================================================================
else
    echo "Uso inválido."
    echo ""
    echo "Comandos disponíveis:"
    echo "  ./run.sh build        -> Constrói a imagem Docker e compila todos os exercícios."
    echo "  ./run.sh <exercicio>  -> Executa um exercício compilado (ex: ./run.sh exc1.1)."
    echo "  ./run.sh fclean       -> Limpa lixo do Docker e binários locais."
    exit 1
fi
