CC = g++
CFLAGS = -std=c++11 -Wall -Wextra
COVFLAGS = -fprofile-arcs -ftest-coverage
PROFFLAGS = -pg
DEBUGFLAGS = -g

MAIN_TARGET = graph

all: $(MAIN_TARGET)

$(MAIN_TARGET): main.o Graph.o
	$(CC) $(CFLAGS) -o $(MAIN_TARGET) main.o Graph.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

Graph.o: Graph.cpp Graph.hpp
	$(CC) $(CFLAGS) -c Graph.cpp

coverage: CFLAGS += $(COVFLAGS)
coverage: $(MAIN_TARGET)
	mkdir -p coverage
	-./$(MAIN_TARGET) -v 5 -e 10 -s 12345
	-./$(MAIN_TARGET) -t 5 -f 10 -q 12345
	-./$(MAIN_TARGET) -v -3 -e -2 -s 12345
	-./$(MAIN_TARGET) -v a -e b -s 12345
	gcov main.cpp -o .
	gcov Graph.cpp -o .
	lcov --capture --directory . --output-file coverage/coverage.info
	genhtml coverage/coverage.info --output-directory coverage/html

profile: CFLAGS += $(PROFFLAGS)
profile: $(MAIN_TARGET)
	mkdir -p profile_data
	./$(MAIN_TARGET) -v 5 -e 10 -s 12345
	gprof $(MAIN_TARGET) gmon.out > profile_data/profile_report.txt
	mv gmon.out profile_data/

memcheck: CFLAGS += $(DEBUGFLAGS)
memcheck: $(MAIN_TARGET)
	valgrind --leak-check=yes --track-origins=yes --gen-suppressions=all ./$(MAIN_TARGET) -v 5 -e 10 -s 12345 > valgrind_output.txt 2>&1

callgraph: CFLAGS += $(DEBUGFLAGS)
callgraph: $(MAIN_TARGET)
	mkdir -p callgraph_data
	valgrind --tool=callgrind ./$(MAIN_TARGET) -v 5 -e 10 -s 12345

	callgrind_annotate --threshold=1 callgrind.out.* > callgraph_report.txt
	mv callgrind.out.* callgraph_data/
	mv callgraph_report.txt callgraph_data/

clean:
	rm -f *.o $(MAIN_TARGET) *.gcda *.gcno *.gcov gmon.out callgrind.out.* valgrind_output.txt callgraph_report.txt
	rm -rf coverage profile_data callgraph_data out

.PHONY: all clean coverage profile valgrind callgraph
