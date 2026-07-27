CXX ?= g++
CXXFLAGS ?= -std=c++17 -O1 -g
BIN := lc_tests
SRCS := $(wildcard *.cpp) $(wildcard solutions/*.cpp)
HEADERS := $(wildcard support/*.hpp)

.PHONY: test build clean
test: build
	./$(BIN)

build: $(BIN)

$(BIN): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -I. -I.. -o $@ $(SRCS)

clean:
	rm -rf $(BIN) $(BIN).dSYM
