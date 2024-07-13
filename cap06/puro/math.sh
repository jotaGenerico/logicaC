#!/bin/bash

# Verifica se foi fornecido um arquivo como argumento
if [ $# -eq 0 ]; then
    echo "Uso: ./math.sh <arquivo.c>"
    exit 1
fi

# Obtém o nome do arquivo fonte e o diretório
file="$1"
file_name=$(basename -- "$file")
file_name_no_ext="${file_name%.*}"
file_dir="$(dirname -- "$file")"
output_dir="$file_dir/output"

# Cria o diretório de saída se não existir
mkdir -p "$output_dir"

# Compila o programa C
echo "Compilando $file..."
gcc -Wall -Wextra -g "$file" -o "$output_dir/$file_name_no_ext" -lm

# Verifica se houve erros na compilação
if [ $? -eq 0 ]; then
    echo "Compilação bem-sucedida. Executando o programa..."
    # Executa o programa compilado no terminal atual
    "$output_dir/$file_name_no_ext"
else
    echo "Erro durante a compilação."
fi
