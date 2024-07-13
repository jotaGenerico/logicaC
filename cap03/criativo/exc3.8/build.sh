#!/bin/bash

# Obtém o diretório atual do script
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# Extrai o nome do diretório do caminho absoluto
DIR_NAME=$(basename "$DIR")

# Compilação do código fonte
gcc "$DIR/main.c" -o "$DIR/$DIR_NAME" -I"$DIR/include" -L"$DIR/lib" -lraylib -lm -lpthread -ldl -lrt -lX11
