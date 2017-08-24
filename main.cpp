/* #include <iostream> */

#include "redux.hpp"
#include "actions.hpp"
#include "store.hpp"

int main() {

  /* store.subscribe(logger); */

	/* store.dispatch(increment(1)); */
	/* // 1 */
	/* store.dispatch(increment(2)); */
	/* // 3 */
	/* store.dispatch(decrement(4)); */
	/* // -1 */
	store.dispatch(increment(7));
	/* // 6 */
  store.dispatch(nameChange("colton"));
  /* store.dispatch(ccwWhite()); */
  store.dispatch(cwWhite());
  /* store.dispatch(ccwGreen()); */
  std::cout << store.getState();
};
