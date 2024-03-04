CXX = clang++

CXXFLAGS = -c -g -Wall -std=c++17 

PROGRAM = a.out

CPPFILES = main.cpp Board/Board.cpp

all:
	$(CXX) $(CXXFLAGS) $(CPPFILES)
	$(CXX) -o $(PROGRAM) *.o 

clean:
	rm -f $(PROGRAM) *.o 
	rm -f $(PROGRAM) *.exe

run: all
	./$(PROGRAM)