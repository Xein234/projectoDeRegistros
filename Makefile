.PHONY: run

build/main: src/main.cpp
	gcc -Wall -pedantic -g -Wextra -pthread -o $@ $<

run: build/main
	./build/main

build/trabajoEnEquipo: src/trabajoEnEquipo.cpp
	gcc -o $@ $<

build/trabajoEnEquipo_test2: src/trabajoEnEquipo_test2.cpp
	g++ src/trabajoEnEquipo_test2.cpp -o build/trabajoEnEquipo_test2
test: build/trabajoEnEquipo_test2
	./build/trabajoEnEquipo_test2
