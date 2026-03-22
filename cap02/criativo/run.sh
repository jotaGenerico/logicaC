#!/bin/bash

# ======================================================================
# CONFIGURAÇÃO DE VARIÁVEIS PARA O CAPÍTULO 2 (PIPE)
# ======================================================================
IMAGEM="raylib-cap02"
DIR="." # Contexto do build: diretório atual
EXERCICIOS="exc2.1|exc2.2|exc2.3|exc2.4"
# ======================================================================

COMANDO="$1"

# -------------------------------------------------------------
# SEÇÃO DE BUILD (Compilar)
# -------------------------------------------------------------
if [ "$COMANDO" = "build" ]; then
    echo "Construindo a imagem Docker '$IMAGEM' e compilando o projeto..."
    docker build -t $IMAGEM $DIR
    if [ $? -eq 0 ]; then
        echo "✅ Compilação concluída. Imagem $IMAGEM criada."
    else
        echo "❌ Falha na compilação Docker. Verifique o Makefile e o Dockerfile."
        exit 1
    fi

# -------------------------------------------------------------
# SEÇÃO DE FCLEAN (Limpeza)
# -------------------------------------------------------------
elif [ "$COMANDO" = "fclean" ]; then
    echo "Executando limpeza profunda (fclean) do Docker..."
    docker rmi -f $IMAGEM 2>/dev/null
    docker system prune --force
    make -C $DIR fclean > /dev/null 2>&1
    echo "✅ Limpeza total concluída."

# -------------------------------------------------------------
# SEÇÃO DE EXECUÇÃO (PIPE/SCANF)
# -------------------------------------------------------------
elif [[ "$COMANDO" =~ ^($EXERCICIOS)$ ]]; then

    BINARIO="./bin/$COMANDO"

    echo "Iniciando a execução gráfica de '$COMANDO' (aguardando entrada via pipe)..."
    xhost +local:docker 2>/dev/null

    # Adiciona -i para capturar o STDIN do pipe
    docker run --rm -i \
               --privileged \
               -e DISPLAY=$DISPLAY \
               -v /tmp/.X11-unix:/tmp/.X11-unix \
               $IMAGEM \
               $BINARIO

    xhost -local:docker 2>/dev/null

else
    echo "Comando inválido. Use build, fclean ou um nome de exercício válido."
    exit 1
fi
# 🚨 FIM DA ESTRUTURA CONDICIONAL (fi)
