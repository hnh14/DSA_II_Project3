CXX = g++
CXXFLAGS = -g -std=c++17 -Wall -Werror=return-type  -Werror=uninitialized 

SRCS = $(wildcard *.hpp)
OBJECTS = $(SRCS:%.hpp=%.o)

CATCH = test/catch/catch.o
TEST_SRCS = $(wildcard test/*.cpp)
TESTS = $(TEST_SRCS:test/%.cpp=%)
#TESTS := $(shell find ./test -name "*cpp")

main: main.cpp matrix.o tour.o
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf *.dSYM
	$(RM) *.o *.gc* test/*.o test/*.gc* *.dSYM $(addprefix test/,$(TESTS)) core main $(CATCH)

$(TESTS): $(CATCH)
	$(CXX) $(CXXFLAGS) -o test/$@ $^
	test/$@ --success

test-all: $(TESTS)
test-1: test/test-1.cpp matrix.o tour.o $(CATCH)
	$(CXX) $(CXXFLAGS) -o test/$@ $^
	test/$@ --success

