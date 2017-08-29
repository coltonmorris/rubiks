#include <string>
#include <boost/any.hpp>

#include "constants.hpp"

typedef std::vector<std::string> Side;
typedef std::vector<Side> Cube;

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
Action setCube(Cube payload) {
	return Action(SET_CUBE, payload);
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
Action cwGreen() {
	return Action(CW_GREEN);
}
Action ccwRed() {
	return Action(CCW_RED);
}
Action cwRed() {
	return Action(CW_RED);
}
Action ccwBlue() {
	return Action(CCW_BLUE);
}
Action cwBlue() {
	return Action(CW_BLUE);
}
Action ccwOrange() {
	return Action(CCW_ORANGE);
}
Action cwOrange() {
	return Action(CW_ORANGE);
}
Action ccwYellow() {
	return Action(CCW_YELLOW);
}
Action cwYellow() {
	return Action(CW_YELLOW);
}
