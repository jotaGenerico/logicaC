#!/bin/bash

IMAGEM="raylib-projetos"
EXERCICIOS="bolinha|olhinhos|pong"

COMANDO="$1"
ARGS="${@:2}"

# --- BUILD: Você roda UMA VEZ para criar o ambiente ---
if [ "$COMANDO" = "build" ]; then
    echo "Criando imagem '$IMAGEM' com os projetos embutidos..."
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
    echo "Uso: ./run.sh [build | bolinha | olhinhos | pong | clean]"
fi
