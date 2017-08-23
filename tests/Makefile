CXXFLAGS := -std=c++11 -Wall -Werror
CXX := g++
HEADERS := $(wildcard *.h)
SRCS    := $(wildcard *.cpp)
OBJECTS := $(patsubst %.cpp,%.o,$(SRCS))
TESTS   := $(wildcard acceptance_tests/test_*.in)
LDFLAGS :=
PROGRAM := rubik_test
TARGETS := $(PROGRAM)


all: $(TARGETS)

$(PROGRAM): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

test: $(PROGRAM)
	@for t in $(TESTS); do \
	  in=$$t; \
	  out=$$(echo $$in | sed 's/\.in$$/.out/'); \
	  echo -n "$$in  "; \
	  ./$(PROGRAM) < $$in > killme; \
	  diff -q -B killme $$out > /dev/null; \
	  if [ $$? -ne 0 ]; then echo "  FAILED"; else echo "  SUCCEEDED"; fi; \
	  rm -f killme; \
	done

memtest: $(PROGRAM)
	rm -f valgrind.log
	-valgrind --leak-check=full --log-file=valgrind.log ./$(PROGRAM)
	cat valgrind.log

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGETS)
	rm -f $(OBJECTS)
	rm -f *~
	rm -f valgrind.log
