CC = gcc
CXX = g++
CFLAGS = -g -O2 -Wall -Wextra -pedantic -std=c11
VALGRIND = valgrind
VGFLAGS = --leak-check=full --show-leak-kinds=all
HELGRIND = valgrind --tool=helgrind

# Source files
SRC1 = hello.c

#Object files
OBJ1 = hello.o

# Targets
TARGET1 = hello

all: hello valgrind_hello

# Build hello.c
hello: $(OBJ1)
	$(CC) $(CFLAGS) -o $(TARGET1) hello.o

hello.o: $(SRC1)
	$(CC) $(CFLAGS) -c $(SRC1)

# Run Valgrind on hello
valgrind_hello: $(TARGET1)
	$(VALGRIND) $(VGFLAGS) ./$(TARGET1) strarg1 strarg2 strarg3

# Clean up
clean:
	rm -f *.o $(TARGET1) $(TARGET2) *.out

.PHONY: all clean valgrind_hello
