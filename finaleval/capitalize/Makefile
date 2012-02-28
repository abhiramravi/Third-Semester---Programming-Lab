# Makefile
#

SH = bash
CFLAGS = -g
LDFLAGS =

all: flow

flow: let_it_flow.o capitalize.o
	gcc $(LDFLAGS) $^ -o $@

let_it_flow.o: let_it_flow.c capitalize.h
	gcc -c $(CFLAGS) $< -o $@

capitalize.o: capitalize.c capitalize.h
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

