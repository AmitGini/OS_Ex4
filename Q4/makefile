CC = g++
CFLAGS = -std=c++11 -Wall -Wextra
COVFLAGS = -fprofile-arcs -ftest-coverage
PROFFLAGS = -pg
DEBUGFLAGS = -g

TARGET = graph

all: $(TARGET)

$(TARGET): main.o Graph.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o Graph.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

Graph.o: Graph.cpp Graph.hpp
	$(CC) $(CFLAGS) -c Graph.cpp

coverage: CFLAGS += $(COVFLAGS)
coverage: $(TARGET)
	./$(TARGET) -v 5 -e 10 -s 12345
	gcov main.cpp
	gcov Graph.cpp

profile: CFLAGS += $(PROFFLAGS)
profile: $(TARGET)
	./$(TARGET) -v 5 -e 10 -s 12345
	gprof $(TARGET) gmon.out > gprof_report.txt

valgrind: CFLAGS += $(DEBUGFLAGS)
valgrind: $(TARGET)
	valgrind --leak-check=full --track-origins=yes ./$(TARGET) -v 5 -e 10 -s 12345

callgrind: CFLAGS += $(DEBUGFLAGS)
callgrind: $(TARGET)
	valgrind --tool=callgrind ./$(TARGET) -v 5 -e 10 -s 12345
	callgrind_annotate callgrind.out.* > callgrind_report.txt

clean:
	rm -f *.o $(TARGET) *.gcda *.gcno *.gcov gmon.out callgrind.out.*

.PHONY: all clean coverage profile valgrind callgrind
