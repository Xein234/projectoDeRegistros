.PHONY: run

build/main: src/main.cpp
	gcc -Wall -pedantic -g -Wextra -pthread -o $@ $<

run: build/main
	./build/main
