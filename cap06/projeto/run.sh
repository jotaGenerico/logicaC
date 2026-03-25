#!/bin/bash

IMAGEM="raylib-cap06-proj"
# Identificador da pasta do projeto
PROJETOS="6.1"

COMANDO="$1"
ARGS="${@:2}"

# --- BUILD ---
if [ "$COMANDO" = "build" ]; then
    echo "Criando imagem '$IMAGEM' para o Projeto do Capitulo 06..."
    docker build -t "$IMAGEM" .

# --- RUN ---
elif [[ "$COMANDO" =~ ^($PROJETOS)$ ]]; then
    xhost +local:docker 2>/dev/null
    # Executa o binário já compilado dentro da imagem
    docker run --rm -it --privileged \
               -e DISPLAY=$DISPLAY \
               -v /tmp/.X11-unix:/tmp/.X11-unix \
               "$IMAGEM" "./bin/$COMANDO" $ARGS
    xhost -local:docker 2>/dev/null

# --- CLEAN ---
elif [ "$COMANDO" = "clean" ]; then
    echo "Deletando a imagem '$IMAGEM'..."
    docker rmi -f "$IMAGEM"

else
    echo "Uso: ./run.sh [build | 6.1 | clean]"
fi
