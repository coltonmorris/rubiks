all: install build

install:
	sudo apt-get install libglu1-mesa-dev mesa-common-dev libxext-dev g++ libxxf86vm-dev libxi-dev freeglut3-dev

build: main.cpp
	g++ -I boost_1_65_0 -o rubik_test -std=c++14 main.cpp
	cp rubik_test tests/

test-glut: test.cpp install
	g++ -o $@ -std=c++11 test.cpp -lglut -lGLU -lGL -lpthread
	./test

	# ./rubik_test < tests/acceptance_tests/test_01.in
test:
	./rubik_test < tmp.txt
