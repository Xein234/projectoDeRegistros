.PHONY: run

build/trabajoEnEquipo: src/trabajoEnEquipo.c
	gcc -Wall -pedantic -g -Wextra -pthread -o $@ $<

run: build/trabajoEnEquipo
	./build/trabajoEnEquipo
