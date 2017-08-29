#include <algorithm>
#include <vector>

#include "actions.hpp"

typedef std::vector<std::string> Side;
typedef std::vector<Side> Cube;
typedef std::pair<int, std::vector<int>> SideRotation;
typedef std::vector<SideRotation> CubeRotation;

class Rubik {
  // map whose keys are color or list whose index is color
  // // contains a map whose keys are an enum of top-left, center, etc.
  // // or is 3 lists, each a row
  // // or is a single list of 9 entries
};

// pretty print cube
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

// pretty print side
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

  /* cube[0][1] = "TEST"; */

  return cube;
}; 

Cube rotateSide(Cube cube, int face, bool isCcw) {
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

Cube rotateCube(Cube cube, int face, bool isCcw, CubeRotation newSides, CubeRotation oldSides) {
  Cube newCube{rotateSide(cube, face, isCcw)};

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      newCube[newSides[i].first][newSides[i].second[j]] = cube[oldSides[i].first][oldSides[i].second[j]];
    }
  }

  return newCube;
}
