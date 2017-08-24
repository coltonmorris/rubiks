#include <algorithm>
#include <vector>

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

  cube[0][1] = "TEST";

  return cube;
}; 

Cube rotateFace(Cube cube, int face, bool isCcw) {
  Cube newCube{cube};
  std::vector<int> newIndex{6,3,0,7,4,1,8,2,5};

  if (isCcw) {
    std::reverse(newIndex.begin(), newIndex.end());
  }
  
  // assign new rotations for this face
  for (int i = 0; i < 9; i++) {
    // ignore the middle
    if (i != 4) {
      newCube[face][i] = cube[face][newIndex[i]];
    }
  }

  return newCube;
}

Cube rotateWhite(Cube cube, bool isCcw) {
  Cube newCube{rotateFace(cube, WHITE, isCcw)};

  std::vector<int> newSides {ORANGE, BLUE, RED, GREEN};
  std::vector<int> oldSides {GREEN, ORANGE, BLUE, RED};

  if (isCcw) {
    std::vector<int> tmp{newSides};
    newSides = oldSides;
    oldSides = tmp;
  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      newCube[newSides[i]][j] = cube[oldSides[i]][j];
    }
  }
  return newCube;
}

Cube ccwGreen(Cube cube) {
  Cube newCube{rotateFace(cube, GREEN, true)};

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
