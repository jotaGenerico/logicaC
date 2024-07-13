#!/bin/bash

# Obtém o nome do diretório atual
dir_name=$(basename "$(pwd)")

# Compila o arquivo main.c no diretório atual
gcc main.c -o "$dir_name" -I/usr/local/include -L/usr/local/lib -lraylib -lm -lpthread -ldl -lrt -lX11
