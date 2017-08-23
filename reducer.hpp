#include <string>

/* typedef std::vector<std::string> Side; */
typedef std::string Side;
typedef std::vector<Side> Cube;

struct State {
  /* Side white {"white", "white", "white", "white", "white", "white", "white", "white", "white"}; */
  Side white {"white"};
  Side green {"green"};
  Side red {"red"};
  Side blue {"blue"};
  Side orange {"orange"};
  Side yellow {"yellow"};
  Cube cube {white, green, red, blue, orange, yellow};
  int count;
  std::string name;

  State() : count(0), name("") {};
};

std::ostream &operator<<(std::ostream &os, Cube const &cube) {
  int size =  cube.size();
  // TODO this must not be an int???
  for (int i=0; i < size; i++) {
    os << cube[0];
  };
};

/* std::ostream &operator<<(std::ostream &os, Side const &side) { */
/*   for (auto i = side.begin(); i != side.end(); ++i) */
/*     os << *i << ' '; */
/* }; */

std::ostream &operator<<(std::ostream &os, State const &state) { 
  os << "State {" << std::endl;
  os << "\t count: " << state.count << std::endl;
  os << "\t name: " << state.name << std::endl;
  os << "\t cube: " << state.cube << std::endl;
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

		default:
			return state;
	};
};
