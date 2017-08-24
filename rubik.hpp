#include <list>

typedef std::vector<std::string> Side;
typedef std::vector<Side> Cube;

class Rubik {
  // map whose keys are color or list whose index is color
  // // contains a map whose keys are an enum of top-left, center, etc.
  // // or is 3 lists, each a row
  // // or is a single list of 9 entries
};

std::ostream &operator<<(std::ostream &os, Cube const &cube) {
  for (int i = 0; i < cube.size(); i++) {
    for (int j = 0; j < cube[i].size(); j++) {
      // print a line if on the third
      if (j % 3 == 0 && j != 0) {
        os << std::endl;
      }

      os << cube[i][j] << " ";
    }
    os << std::endl;
    // trim extra newline
    if ( i != cube.size() - 1 ) {
      os << std::endl;
    }
  }
  return os;
};

std::ostream &operator<<(std::ostream &os, Side const &side) {
  for (int i = 0; i < side.size(); i++) {
    // print a line if on the third
    if (i % 3 == 0 && i != 0) {
      os << std::endl;
    }
    os << side[i] << " ";
  }
  os << std::endl;
  return os;
};

Cube initializeCube() {
  Cube cube{};
  std::vector<std::string> colorNames{"white", "green", "red", "blue", "orange", "yellow"};
  for (int i = 0; i < 6; i++) {
    Side side{};
    for (int j = 0; j < 9; j++) {
      side.push_back(colorNames[i]);
    }
    cube.push_back(side);
  }

  return cube;
}; 

Cube rotateCcw(Cube cube, int face) {
  Cube newCube{cube};

  for (int j = 0; j < 9; j++) {
    /* cube[face].push_back(colorNames[i]); */
  }
  return cube;
}

Cube ccwWhite(Cube cube) {
  /*  red -> blue
   *  blue -> orange
   *  orange -> green
   *  green -> red
   *  white -> white
   */
  Cube newCube{cube};

  newCube[WHITE][0] = cube[WHITE][2];
  newCube[WHITE][1] = cube[WHITE][5];
  newCube[WHITE][2] = cube[WHITE][8];
  newCube[WHITE][3] = cube[WHITE][1];
  newCube[WHITE][5] = cube[WHITE][7];
  newCube[WHITE][6] = cube[WHITE][0];
  newCube[WHITE][7] = cube[WHITE][3];
  newCube[WHITE][8] = cube[WHITE][6];
  // clock wise: 
  /* newCube[WHITE][0] = cube[WHITE][6]; */
  /* newCube[WHITE][1] = cube[WHITE][3]; */
  /* newCube[WHITE][2] = cube[WHITE][0]; */
  /* newCube[WHITE][3] = cube[WHITE][7]; */
  /* newCube[WHITE][5] = cube[WHITE][1]; */
  /* newCube[WHITE][6] = cube[WHITE][8]; */
  /* newCube[WHITE][7] = cube[WHITE][5]; */
  /* newCube[WHITE][8] = cube[WHITE][2]; */

  newCube[GREEN][0] = cube[ORANGE][0];
  newCube[GREEN][1] = cube[ORANGE][1];
  newCube[GREEN][2] = cube[ORANGE][2];

  newCube[ORANGE][0] = cube[BLUE][0];
  newCube[ORANGE][1] = cube[BLUE][1];
  newCube[ORANGE][2] = cube[BLUE][2];

  newCube[BLUE][0] = cube[RED][0];
  newCube[BLUE][1] = cube[RED][1];
  newCube[BLUE][2] = cube[RED][2];

  newCube[RED][0] = cube[GREEN][0];
  newCube[RED][1] = cube[GREEN][1];
  newCube[RED][2] = cube[GREEN][2];

  return newCube;
}

Cube ccwGreen(Cube cube) {
  Cube newCube{cube};

  newCube[GREEN][0] = cube[GREEN][2];
  newCube[GREEN][1] = cube[GREEN][5];
  newCube[GREEN][2] = cube[GREEN][8];
  newCube[GREEN][3] = cube[GREEN][1];
  newCube[GREEN][5] = cube[GREEN][7];
  newCube[GREEN][6] = cube[GREEN][0];
  newCube[GREEN][7] = cube[GREEN][3];
  newCube[GREEN][8] = cube[GREEN][6];

  newCube[WHITE][0] = cube[RED][0];
  newCube[WHITE][3] = cube[RED][3];
  newCube[WHITE][6] = cube[RED][6];

  newCube[ORANGE][2] = cube[WHITE][0];
  newCube[ORANGE][5] = cube[WHITE][3];
  newCube[ORANGE][8] = cube[WHITE][6];

  newCube[YELLOW][0] = cube[ORANGE][2];
  newCube[YELLOW][3] = cube[ORANGE][5];
  newCube[YELLOW][6] = cube[ORANGE][8];

  newCube[RED][0] = cube[YELLOW][0];
  newCube[RED][3] = cube[YELLOW][3];
  newCube[RED][6] = cube[YELLOW][6];

  return newCube;
}
