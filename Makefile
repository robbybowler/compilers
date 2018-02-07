CXXFLAGS := -std=c++11 -g
CXX := g++
OBJECTS := main.o Token.o StateMachine.o Scanner.o
PROGRAM := main
TARGETS := $(PROGRAM)

all: $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

check: $(PROGRAM)
	./$(PROGRAM)

clean:
	rm -f $(TARGETS)
	rm -f *.o *~
