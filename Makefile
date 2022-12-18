.PHONY: run

build/trabajoEnEquipo: src/trabajoEnEquipo.cpp
	gcc -Wall -pedantic -g -Wextra -pthread -o $@ $<

run: build/trabajoEnEquipo
	./build/trabajoEnEquipo
