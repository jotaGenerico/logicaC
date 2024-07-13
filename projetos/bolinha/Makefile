# Makefile para Linux
#
# Uso:
#    make: clean, compile and run
#    make clean: clean compiled file
#    make cleanAndCompile: clean compiled file and compile the project
#    make compile: compile the project
#    make compileAndRun: compile the project and run the compiled file
#    make run: run the compiled file
#
# Autor: Prof. Dr. David Buzatto

currentFolderName := $(notdir $(shell pwd))
compiledFile := $(currentFolderName)
CFLAGS := -O1 -Wall -Wextra -Wno-unused-parameter -pedantic-errors -std=c99 -Wno-missing-braces -I include/ -L lib/ -lraylib -lm -ldl -lpthread -lrt -lX11

all: clean compile run

clean:
	rm -f $(compiledFile)

compile:
	gcc *.c -o $(compiledFile) $(CFLAGS)

run:
	./$(compiledFile)

cleanAndCompile: clean compile
compileAndRun: compile run
