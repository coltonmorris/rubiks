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

    case CCW_WHITE: {
      SideRotation orange (ORANGE, std::vector<int>{0,1,2});
      SideRotation blue (BLUE, std::vector<int>{0,1,2});
      SideRotation red (RED, std::vector<int>{0,1,2});
      SideRotation green (GREEN, std::vector<int>{0,1,2});
      CubeRotation newSides {green, orange, blue, red};
      CubeRotation oldSides {orange, blue, red, green};
      state.cube = rotateCube(state.cube, WHITE, true, newSides, oldSides);
      return state;
    }

    case CW_WHITE: {
      SideRotation orange (ORANGE, std::vector<int>{0,1,2});
      SideRotation blue (BLUE, std::vector<int>{0,1,2});
      SideRotation red (RED, std::vector<int>{0,1,2});
      SideRotation green (GREEN, std::vector<int>{0,1,2});
      CubeRotation newSides {orange, blue, red, green};
      CubeRotation oldSides {green, orange, blue, red};
      state.cube = rotateCube(state.cube, WHITE, false, newSides, oldSides);
      return state;
    }

    case CCW_GREEN: {
      SideRotation white (WHITE, std::vector<int>{0,3,6});
      SideRotation orange (ORANGE, std::vector<int>{2,5,8});
      SideRotation yellow (YELLOW, std::vector<int>{0,3,6});
      SideRotation red (RED, std::vector<int>{0,3,6});
      CubeRotation newSides {white, orange, yellow, red};
      CubeRotation oldSides {red, white, orange, yellow};
      state.cube = rotateCube(state.cube, GREEN, true, newSides, oldSides);
      return state;
    }

    case CW_GREEN: {
      SideRotation white (WHITE, std::vector<int>{0,3,6});
      SideRotation orange (ORANGE, std::vector<int>{2,5,8});
      SideRotation red (RED, std::vector<int>{0,3,6});
      SideRotation yellow (YELLOW, std::vector<int>{0,3,6});
      CubeRotation newSides {red, white, orange, yellow};
      CubeRotation oldSides {white, orange, yellow, red};
      state.cube = rotateCube(state.cube, GREEN, false, newSides, oldSides);
      return state;
    }

		default:
			return state;
	};
};
