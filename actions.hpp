#include <string>
#include <boost/any.hpp>

#include "constants.hpp"

class Action { // lawsuit
	public:
		ActionType type;
    boost::any payload;

    // no payload
    Action(ActionType type) : type(type) {};

		Action(ActionType type, boost::any payload) : type(type), payload(payload) {};
};


// action creators
Action increment(int payload) {
	return Action(INCREMENT, payload);
}
Action decrement(int payload) {
	return Action(DECREMENT, payload);
}
Action nameChange(std::string payload) {
	return Action(NAME_CHANGE, payload);
}
Action ccwWhite() {
	return Action(CCW_WHITE);
}
Action cwWhite() {
	return Action(CW_WHITE);
}
Action ccwGreen() {
	return Action(CCW_GREEN);
}
