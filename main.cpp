#include <boost/tokenizer.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

#include "redux.hpp"
#include "actions.hpp"
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

enum Commands {
  INITIAL,
  ROTATE,
  SHOW,
  ISEQUAL
};

/*
   Turn string s into a vector of types T
 */
template<class T>
void tokenizeV(const std::string &s,
          std::vector<T> &o)
{
  typedef boost::tokenizer<boost::escaped_list_separator<char> >  tok_t;

  tok_t tok(s);
  for(tok_t::iterator j (tok.begin());
      j != tok.end();
      ++j)
  {
    std::string f(*j);
    boost::trim(f);
    o.push_back(boost::lexical_cast<T>(f));
  }
}

/* Cube tokenizeCube(const std::vector<std::string> &inputCube) { */
/*   Cube cube{}; */
/*   typedef boost::tokenizer<boost::escaped_list_separator<char> >  tok_t; */

/*   std::vector<std::string> colorNames{"white", "green", "red", "blue", "orange", "yellow"}; */

/*   for (int i = 0; i < 6; i++) { */
/*     Side side{}; */
/*     for (int j = 0; j < 9; j++) { */
/*       side.push_back(colorNames[i]); */
/*     } */
/*     cube.push_back(side); */
/*   } */

/*   cube[0][1] = "TEST"; */

/*   return cube; */
/*   tok_t tok(s); */
/*   for(tok_t::iterator j (tok.begin()); */
/*       j != tok.end(); */
/*       ++j) */
/*   { */
/*     std::string f(*j); */
/*     boost::trim(f); */
/*     o.push_back(boost::lexical_cast<T>(f)); */
/*   } */
/* } */

Cube createCubeFromInput() {
  // TODO the cube is being made with an empty line as the sides. loop through the sides of the cube first and see what those look like
  // It's definitely adding a line
  Cube cube{};
  std::string input;
  std::vector<std::string> SideRow;

  for (int i = 0; i < 18; i++) {
    std::getline(std::cin, input);

    if (input.empty()) {
      std::cout << "empty line, not adding" << std::endl;
      i--;
      continue;
    }
    std::cout << "non empty line, adding" << std::endl;
      i--;

    Side side{};
    boost::split(SideRow, input, boost::is_any_of("\t "));

    side.push_back(SideRow[0]);
    side.push_back(SideRow[1]);
    side.push_back(SideRow[2]);

    cube.push_back(side);
  }

  std::cout << "LOOK HERE: " << std::endl;
  std::cout << cube[1] << std::endl;
  std::cout << "LOOK HERE: " << std::endl;
  return cube;
}

int main() {
  std::string input;
  std::vector<std::string> line;

  while (std::getline(std::cin, input)) {
    // TODO:
    // if input is EOF, break

    boost::split(line, input, boost::is_any_of("\t "));

    if (line[0] == "initial") {
      Cube inputCube{createCubeFromInput()};
      std::cout << "Created cube: " << std::endl;
      std::cout << inputCube;
    }
    else if (line[0] == "show") {
      std::cout << store.getState().cube;
    }
    else if (line[0] == "isequal") {
      // read an input cube
      std::cout << "checking isequal" << std::endl;
    }
    else if (line[0] == "rotate") {
      if (line[1] == "done") {
        continue;
      }
      // read an input cube
      std::cout << "rotating" << std::endl;
    }
    else if (line[0] == "exit") {
      break;
    }
    else {
      std::cout << "default" << std::endl;
      continue;
    }
  }

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
  store.dispatch(cwWhite());
  /* store.dispatch(cwWhite()); */
  /* store.dispatch(ccwGreen()); */
  /* store.dispatch(cwGreen()); */
  std::cout << store.getState();

  //TODO start using the acceptance testing!
};
