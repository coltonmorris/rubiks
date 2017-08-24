#include <iostream>
#include "redux.hpp"
#include "reducer.hpp"

Cube cube = initializeCube();

// initialize store with initial state
redux::Store<State, Action> store(reducer, State{cube});

// state logger
void logger(State state) {
	std::cout << state << std::endl;
}
