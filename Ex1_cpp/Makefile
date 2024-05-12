#name: Maayan Sher
#id: 208731091
#Email: maayan1sher@gmail.com

#!make -f

CXX=g++
CXXFLAGS=-std=c++11 -Werror -Wsign-conversion
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

SOURCES=Graph.cpp Algorithms.cpp TestCounter.cpp Test.cpp
OBJECTS=$(subst .cpp,.o,$(SOURCES))

all: main
	./$^

main: main.o Graph.cpp Algorithms.cpp
	$(CXX) $(CXXFLAGS) $^ -o main

test: TestCounter.o Test.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test


valgrind: main test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./main 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o main test