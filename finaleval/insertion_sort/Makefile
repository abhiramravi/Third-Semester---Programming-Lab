# Makefile
#

CC = gcc
SH = bash
CFLAGS = -g
LDFLAGS = -lm

PROG = sort

all: $(PROG)

$(PROG): $(PROG).o insertion_sort.o

$(PROG).o: $(PROG).c insertion_sort.h

insertion_sort.o: insertion_sort.c insertion_sort.h


.PHONY: clean lint test

clean:
	rm -rf *.o
	rm -rf tests/*_
	rm -rf $(PROG)

lint:

test: all
	$(SH) tests/run_tests.sh

