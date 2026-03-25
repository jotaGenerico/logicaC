#!/bin/bash

IMAGEM="raylib-cap06"
# Regex atualizada para os exercícios do Capítulo 6
EXERCICIOS="exc6.1|exc6.2|exc6.3|exc6.4|exc6.5"

COMANDO="$1"
ARGS="${@:2}"

# --- BUILD ---
if [ "$COMANDO" = "build" ]; then
    echo "Criando imagem '$IMAGEM' para o Capitulo 06..."
    docker build -t "$IMAGEM" .

# --- RUN ---
elif [[ "$COMANDO" =~ ^($EXERCICIOS)$ ]]; then
    xhost +local:docker 2>/dev/null
    # Roda o binário que já foi compilado dentro da imagem
    docker run --rm -it --privileged \
               -e DISPLAY=$DISPLAY \
               -v /tmp/.X11-unix:/tmp/.X11-unix \
               "$IMAGEM" "./bin/$COMANDO" $ARGS
    xhost -local:docker 2>/dev/null

# --- CLEAN ---
elif [ "$COMANDO" = "clean" ]; then
    echo "Deletando a imagem '$IMAGEM' do sistema..."
    docker rmi -f "$IMAGEM"

else
    echo "Uso: ./run.sh [build | exc6.x | clean]"
fi
