# Simple Makefile

# Your compiler
CC = gcc
# Compilation flags
# '-g' turns debugging flags on.
CFLAGS = -g

# Linker flags
# When you need to add a library
# '-lm' adds the math library
LDFLAGS = -lm

# all is a target. main is a 'dependency' or requirement for all to be complete
all: main

# The main program depends on the complex number library, and the main file
main: main.o matrix.o
	$(CC) $(LDFLAGS) -o $@ $^			# $@ stores the target, 'main' $^ stores all the dependencies 'main.o complex.o'
	# the main.o can be replaced by anythingthathasmain.o

main.o: main.c matrix.h
	$(CC) -c $(CFLAGS) -o $@ $<			# $< stores the first target, just the '.c' file (we won't compile the .h files)

matrix.o: matrix.c matrix.h
	$(CC) -c $(CFLAGS) -o $@ $<			# $< stores the first target, just the '.c' file (we won't compile the .h file)

# .PHONY tells make that 'all' or 'clean' aren't _actually_ files, and always
# execute the compilation action when 'make all' or 'make clean' are used
.PHONY: all clean							

# Delete all the temporary files we've created so far
clean:
	rm -rf main.o matrix.o
	rm -rf main

