# Makefile
#

SH = bash
CFLAGS = -g
LDFLAGS = -lm

all: token

# Write Makefile rules to compile the main program, token, as well as
# the BSTree library

.PHONY: clean lint test

clean:
	rm -rf *.o
	rm -rf token
	rm -rf tests/*_

lint:
	for f in *.c; do echo $$f; splint -standard $$f; done;

test: all
	$(SH) tests/run_tests.sh

