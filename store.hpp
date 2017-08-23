#include "redux.hpp"
#include "reducer.hpp"

State initialState{0};

// initialize store with initial state
redux::Store<State, Action> store(reducer, initialState);

// state logger
void logger(State state) {
	std::cout << state << std::endl;
}
