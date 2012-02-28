# Makefile
#

SH = bash
CFLAGS = -g
LDFLAGS =

all: stacks

stacks: sum.o stacks.o
	gcc $(LDFLAGS) $^ -o $@

sum.o: sum.c sum.h
	gcc -c $(CFLAGS) $< -o $@

stacks.o: stacks.c sum.h
	gcc -c $(CFLAGS) $< -o $@

.PHONY: clean lint test

clean:
	rm -rf *.o
	rm -rf flow
	rm -rf tests/*_

lint:
	for f in *.c; do echo $$f; splint -standard $$f; done;

test: all
	$(SH) tests/run_tests.sh

