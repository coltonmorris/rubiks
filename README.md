Here's the gist of it, left out some stuff for clarity sake

### Action Types
---
```cpp
enum ActionType {
  INCREMENT,
  DECREMENT,
  NAME_CHANGE,
};
```

### Action Creators
---
```cpp
Action increment(int payload) {
	return Action(INCREMENT, payload);
}
Action decrement(int payload) {
	return Action(DECREMENT, payload);
}
Action nameChange(std::string payload) {
	return Action(NAME_CHANGE, payload);
}
```

### State
---
```cpp
struct State {
  int count;
  std::string name;

  //initial state
  State() : count(0), name("") {};
};
```

### Store
---
```cpp
// initialize store with initial state
redux::Store<State, Action> store(reducer, State{});
```

### Reducer
---
```cpp
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
```

### Dispatch Actions
---
```cpp
store.dispatch(increment(1));
store.dispatch(nameChange("colton"));

std::cout << store.getState();
// count: 1, name: "colton"
```
