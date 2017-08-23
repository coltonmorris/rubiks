#include <string>

struct State {
  int count;
  std::string name;

  State() : count(0), name("") {};
};

std::ostream &operator<<(std::ostream &os, State const &state) { 
  os << "State {" << std::endl;
  os << "\t count: " << state.count << std::endl;
  os << "\t name: " << state.name << std::endl;
  return os << "}";
}

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
	}
};
