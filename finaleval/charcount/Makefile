# Makefile
#

CC = gcc
SH = bash
CFLAGS = -g
LDFLAGS = -lm

PROG = charcount

all: $(PROG)

$(PROG): $(PROG).c

.PHONY: clean lint test

clean:
	rm -rf *.o
	rm -rf tests/*_
	rm -rf $(PROG)

lint:

test: all
	$(SH) tests/run_tests.sh


