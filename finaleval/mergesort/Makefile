# Makefile
#

CC = gcc
SH = bash
CFLAGS = -g
LDFLAGS = -lm

PROG = sort

all: $(PROG)

$(PROG): $(PROG).o mergesort.o

$(PROG).o: $(PROG).c mergesort.h

mergesort.o: mergesort.c mergesort.h


.PHONY: clean lint test

clean:
	rm -rf *.o
	rm -rf tests/*_
	rm -rf $(PROG)

lint:

test: all
	$(SH) tests/run_tests.sh

