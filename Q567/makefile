CC = gcc
CXX = g++
CFLAGS = -g -O2 -Wall -Wextra -pedantic -std=c11
VALGRIND = valgrind
VGFLAGS = --leak-check=full --show-leak-kinds=all
HELGRIND = valgrind --tool=helgrind

# Source files
SRC1 = hello.c
SRC2 = race.c

#Object files
OBJ1 = hello.o
OBJ2 = race.o

# Targets
TARGET1 = hello
TARGET2 = race

all: hello race valgrind_hello valgrind_race

# Build hello.c
hello: $(OBJ1)
	$(CC) $(CFLAGS) -o $(TARGET1) hello.o

# Build race.c
race: $(OBJ2)
	$(CC) $(CFLAGS) -o $(TARGET2) race.o

hello.o: $(SRC1)
	$(CC) $(CFLAGS) -c $(SRC1)

race.o: $(SRC2)
	$(CC) $(CFLAGS) -c $(SRC2)

# Run Valgrind on hello
valgrind_hello: $(TARGET1)
	$(VALGRIND) $(VGFLAGS) ./$(TARGET1) arg1 arg2 arg3

# Run Valgrind/Helgrind on race
valgrind_race: $(TARGET2)
	$(HELGRIND) ./$(TARGET2)

# Clean up
clean:
	rm -f *.o $(TARGET1) $(TARGET2) *.out

.PHONY: all clean valgrind_hello valgrind_race
