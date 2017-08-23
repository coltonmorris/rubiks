all: check

check: test install
	./main_test

install:
	sudo apt-get install libglu1-mesa-dev mesa-common-dev libxext-dev g++ libxxf86vm-dev libxi-dev freeglut3-dev

test-glut: test.cpp install
	g++ -o $@ -std=c++11 test.cpp -lglut -lGLU -lGL -lpthread
	./test

test: main.cpp
	g++ -I boost_1_65_0 -o main_test -std=c++14 main.cpp
	./main_test
