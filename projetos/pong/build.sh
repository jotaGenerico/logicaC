#!/bin/bash

# Nome do arquivo compilado
currentFolderName=$(basename "$PWD")
compiledFile="$currentFolderName"

# Flags de compilação
CFLAGS="-O1 -Wall -Wextra -Wno-unused-parameter -pedantic-errors -std=c99 -Wno-missing-braces -I include/ -L lib/ -lraylib -lm -ldl -lpthread -lrt -lX11"

function clean {
    echo "Cleaning..."
    rm -f "$compiledFile"
}

function compile {
    echo "Compiling..."
    gcc *.c -o "$compiledFile" $CFLAGS
}

function run {
    echo "Running..."
    if [ -f "$compiledFile" ]; then
        ./"$compiledFile"
    else
        echo "$compiledFile does not exist!"
    fi
}

# Funções para cada opção
case "$1" in
    -clean)
        clean
        ;;
    -cleanAndCompile)
        clean
        compile
        ;;
    -compile)
        compile
        ;;
    -compileAndRun)
        compile
        run
        ;;
    -run)
        run
        ;;
    *)
        clean
        compile
        run
        ;;
esac
