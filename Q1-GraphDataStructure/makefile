CC = g++
CFLAGS = -std=c++11 -Wall -Wextra

TARGET = graph

all: $(TARGET)

$(TARGET): main.o Graph.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o Graph.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

Graph.o: Graph.cpp Graph.hpp
	$(CC) $(CFLAGS) -c Graph.cpp

clean:
	rm -f *.o $(TARGET)

.PHONY: all clean