#!/bin/bash

# ======================================================================
# Script de Gerenciamento Raylib Docker (build, run, fclean)
#
# Uso: ./run.sh [build | <nome_do_exercicio> | fclean]
# Este modelo suporta:
# 1. Entrada de dados interativa via terminal (scanf/printf).
# 2. Execução gráfica Raylib.
# ======================================================================

# ======================================================================
# 🚨 CONFIGURAÇÃO DE VARIÁVEIS POR CAPÍTULO 🚨
# ======================================================================
IMAGEM="raylib-cap01"           # 1. EDITE: Nome da imagem (Ex: raylib-cap01)
DIR="."                         # Contexto do build: diretório atual
# 2. EDITE: Lista de todos os exercícios do capítulo, separados por pipe '|'
EXERCICIOS="olaRaylib|exc1.1|exc1.2|exc1.3|exc1.4|exc1.5|exc1.6|exc1.7|exc1.8|exc1.9"
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

    # Limpa binários locais antes de construir
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

    # Remove a imagem compilada
    docker rmi -f $IMAGEM 2>/dev/null

    # Remove imagens pendentes e cache
    docker system prune --force

    # Remove binários locais
    make fclean > /dev/null 2>&1

    echo "✅ Limpeza total concluída. O ambiente está limpo."

# ======================================================================
# Ação: RUN (Executar um exercício)
# ======================================================================
# Usa a variável EXERCICIOS, aceitando qualquer nome listado.
elif [[ "$COMANDO" =~ ^($EXERCICIOS)$ ]]; then

    BINARIO="./bin/$COMANDO"

    echo "Iniciando a execução interativa e gráfica de '$COMANDO'..."

    # PASSO 1: Adiciona permissão temporária para acesso ao X Server
    xhost +local:docker 2>/dev/null

    # PASSO 2: Executa o contêiner com TTY interativo e acesso gráfico
    docker run --rm \
               -i -t \
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
