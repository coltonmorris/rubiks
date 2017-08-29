#include <boost/algorithm/string.hpp> // for splitting
#include <boost/function.hpp> // for map of functions
#include <boost/bind.hpp> // for map of functions
#include <iostream>
#include <map>

#include "store.hpp"

/* POSSIBLE COMMANDS:
 * initial:
 *    empty line,
 *    then each 6 sides split by empty line
 *
 *  rotate:
 *    rotate face cw
 *       
 *  rotate done:
 *    shows that rotate commands are no longer happening
 *
 *  show: 
 *      print the cube.
 *       - No first empty line,
 *       - Empty line between sides,
 *       - No empty line at the end
 *
 *  isequal:
 *    empty line, then a cube to compare to
 *    print TRUE or FALSE after comparison
 *       
 *       
 *  PLAN OF ACTION:
 *    - take inputs and dispatch actions for each input
 *    - dont care about order of inputs!
 *
 */

Cube createCubeFromInput() {
  Cube cube{};
  Side side{};
  std::string input;

  for (int i = 0; i < 18; i++) {
    std::getline(std::cin, input, '\n');

    if (input.empty()) {
      i--;
      continue;
    }
    std::vector<std::string> SideRow{};

    boost::split(SideRow, input, boost::is_any_of("\t "));

    side.push_back(SideRow[0]);
    side.push_back(SideRow[1]);
    side.push_back(SideRow[2]);

    if (side.size() == 9) {
      cube.push_back(side);
      side.clear();
    }
  }

  return cube;
}

int main() {
  typedef boost::function<Action (void)> ActionFuncs;
  typedef std::map<std::string, ActionFuncs> RotateFuncs;
  RotateFuncs rotateFuncs;

  rotateFuncs["white cw"] = cwWhite;
  rotateFuncs["white ccw"] = ccwWhite;
  rotateFuncs["green cw"] = cwGreen;
  rotateFuncs["green ccw"] = ccwGreen;
  rotateFuncs["red cw"] = cwRed;
  rotateFuncs["red ccw"] = ccwRed;
  rotateFuncs["blue cw"] = cwBlue;
  rotateFuncs["blue ccw"] = ccwBlue;
  rotateFuncs["orange cw"] = cwOrange;
  rotateFuncs["orange ccw"] = ccwOrange;
  rotateFuncs["yellow cw"] = cwYellow;
  rotateFuncs["yellow ccw"] = ccwYellow;

  std::string input;
  std::vector<std::string> line;

  while (std::getline(std::cin, input, '\n')) {
    boost::split(line, input, boost::is_any_of("\t "));

    if (line[0] == "initial") {
      Cube inputCube{createCubeFromInput()};
      store.dispatch(setCube(inputCube));
    }
    else if (line[0] == "show") {
      std::cout << store.getState().cube;
    }
    else if (line[0] == "isequal") {
      std::cout << std::endl;

      // read an input cube
      Cube inputCube{createCubeFromInput()};

      if (inputCube == store.getState().cube) {
        std::cout << "TRUE" << std::endl;
      }
      else {
        std::cout << "FALSE" << std::endl;
      }
    }
    else if (line[0] == "rotate") {
      if (line[1] == "done") {
        continue;
      }

      store.dispatch(rotateFuncs[line[1] + " " + line[2]]());
    }
  }

  /* store.subscribe(logger); */

	/* store.dispatch(increment(1)); */
	/* // 1 */
	/* store.dispatch(increment(2)); */
	/* // 3 */
	/* store.dispatch(decrement(4)); */
	/* // -1 */
	/* store.dispatch(increment(7)); */
	/* // 6 */
  /* store.dispatch(nameChange("colton")); */
  /* store.dispatch(cwWhite()); */
  /* store.dispatch(cwWhite()); */
  /* store.dispatch(ccwGreen()); */
  /* store.dispatch(cwGreen()); */
  /* std::cout << store.getState().cube; */
};
