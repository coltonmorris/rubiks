#include "redux.hpp"
#include "reducer.hpp"

// initialize store with initial state
redux::Store<State, Action> store(reducer, State{});

// state logger
void logger(State state) {
	std::cout << state << std::endl;
}
