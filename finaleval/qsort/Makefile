# Makefile
#

CC = gcc
SH = bash
CFLAGS = -g
LDFLAGS = -lm

PROG = sort

all: $(PROG)

$(PROG): $(PROG).o qsort.o LList.o Stack.o

$(PROG).o: $(PROG).c qsort.h

qsort.o: qsort.c qsort.h

LList.o: LList.c LList.h

Stack.o: Stack.c Stack.h

.PHONY: clean lint test

clean:
	rm -rf *.o
	rm -rf tests/*_
	rm -rf $(PROG)

lint:

test: all
	$(SH) tests/run_tests.sh

