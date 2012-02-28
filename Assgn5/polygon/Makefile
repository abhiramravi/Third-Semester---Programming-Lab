# Makefile
#

SH = bash
CFLAGS = -g
LDFLAGS = -lm

all: area

area: area.o Point.o CLinkedList.o Polygon.o
	gcc $(LDFLAGS) $^ -o $@

area.o: area.c Polygon.h CLinkedList.h Point.h  
	gcc -c $(CFLAGS) $< -o $@

Polygon.o: Polygon.c Polygon.h CLinkedList.h Point.h
	gcc -c $(CFLAGS) $< -o $@

CLinkedList.o: CLinkedList.c CLinkedList.h Point.h
	gcc -c $(CFLAGS) $< -o $@

Point.o: Point.c Point.h
	gcc -c $(CFLAGS) $< -o $@

.PHONY: clean lint test

clean:
	rm -rf *.o
	rm -rf area
	rm -rf tests/*_

lint:
	for f in *.c; do echo $$f; splint -standard $$f; done;

test: all
	$(SH) tests/run_tests.sh

