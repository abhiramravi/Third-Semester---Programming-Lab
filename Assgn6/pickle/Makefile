# Makefile
#

SH = bash
CFLAGS = -g
LDFLAGS = -lm

all: pickle

pickle: pickle.o MatrixRational.o rational.o
	gcc $(LDFLAGS) $^ -o $@

pickle.o: pickle.c MatrixRational.h 
	gcc -c $(CFLAGS) $< -o $@

MatrixRational.o: MatrixRational.c MatrixRational.h rational.h
	gcc -c $(CFLAGS) $< -o $@

rational.o: rational.c rational.h
	gcc -c $(CFLAGS) $< -o $@

.PHONY: clean lint test

clean:
	rm -rf *.o
	rm -rf pickle
	rm -rf tests/*_

lint:
	for f in *.c; do echo $$f; splint -standard $$f; done;

test: all
	$(SH) tests/run_tests.sh

