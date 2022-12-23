.PHONY: run test

CC     = g++
CFLAGS = -Wall -pedantic -g -Wextra -pthread -std=c++20

build/%.o: src/%.cpp
	mkdir -p build
	$(CC) -c -MD $(CFLAGS) $< -o $@

-include build/*.d

build/main: build/main.o build/trabajoEnEquipo.o
	$(CC) $(CFLAGS) $^ -o $@

run: build/main
	./build/main

build/trabajoEnEquipo_test2: build/trabajoEnEquipo_test2.o build/trabajoEnEquipo.o
	$(CC) $(CFLAGS) $^ -o $@

test: build/trabajoEnEquipo_test2
	./build/trabajoEnEquipo_test2
