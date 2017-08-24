#include <string>
#include <iostream>
#include "rubik.hpp"


struct State {
  int count;
  std::string name;
  Cube cube;

  State() : count(0), name("") {};
  State(Cube cube) : count(0), name(""), cube(cube) {};
};


std::ostream &operator<<(std::ostream &os, State const &state) { 
  os << "State {" << std::endl;
  os << "\t count: " << state.count << std::endl;
  os << "\t name: " << state.name << std::endl;
  os << "\t cube: {" << std::endl << state.cube;
  os << "}" << std::endl;
  return os << "}";
};

State reducer(State state, Action action) {
	switch(action.type) {
		case INCREMENT:

      state.count += boost::any_cast<int>(action.payload);
			return state;

		case DECREMENT:
      state.count -= boost::any_cast<int>(action.payload);
			return state;

    case NAME_CHANGE:
      state.name = boost::any_cast<std::string>(action.payload);
      return state;

    case CCW_WHITE:
      state.cube = rotateWhite(state.cube, true);
      return state;

    case CW_WHITE:
      state.cube = rotateWhite(state.cube, false);
      return state;

    case CCW_GREEN:
      state.cube = ccwGreen(state.cube);
      return state;

		default:
			return state;
	};
};
