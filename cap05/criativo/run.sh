#!/bin/bash

IMAGEM="raylib-cap05"
EXERCICIOS="exc5.1|exc5.2|exc5.1mouse|exc5.2mouse"

COMANDO="$1"
ARGS="${@:2}"

# --- BUILD: Você roda UMA VEZ para criar o ambiente ---
if [ "$COMANDO" = "build" ]; then
    echo "Criando imagem '$IMAGEM' com os exercicios embutidos..."
    docker build -t "$IMAGEM" .

# --- RUN: Você roda QUANTAS VEZES QUISER sem reconstruir ---
elif [[ "$COMANDO" =~ ^($EXERCICIOS)$ ]]; then
    xhost +local:docker 2>/dev/null
    # Roda o binário que já está dentro da imagem
    docker run --rm -it --privileged \
               -e DISPLAY=$DISPLAY \
               -v /tmp/.X11-unix:/tmp/.X11-unix \
               "$IMAGEM" "./bin/$COMANDO" $ARGS
    xhost -local:docker 2>/dev/null

# --- CLEAN: Você decide quando deletar a imagem do PC ---
elif [ "$COMANDO" = "clean" ]; then
    echo "Deletando a imagem '$IMAGEM' do sistema..."
    docker rmi -f "$IMAGEM"

else
    echo "Uso: ./run.sh [build | exc5.x | clean]"
fi
