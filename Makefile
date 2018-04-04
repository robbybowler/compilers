CXXFLAGS := -std=c++11 -g
CXX := g++
OBJECTS := nodeTest.o Node.o Symbol.o
PROGRAM := nodeTest
TARGETS := $(PROGRAM)

all: $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

check: $(PROGRAM)
	./$(PROGRAM)

clean:
	rm -f $(TARGETS)
	rm -f *.o *~
