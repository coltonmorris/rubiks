FROM gcc:5.4.0

COPY . /usr/src/

WORKDIR /usr/src

RUN apt-get -y update
RUN apt-get -y install libglu1-mesa-dev mesa-common-dev libxext-dev g++ libxxf86vm-dev libxi-dev freeglut3-dev

RUN g++ -o test -std=c++11 test.cpp -lglut -lGLU -lGL -lpthread

CMD ["./test"]
