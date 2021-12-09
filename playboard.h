#pragma once
#include <vector>

class Playboard {
  std::vector<char> board;

public:
  
  Playboard (int size);
  int size();
  void clear ();
  void reset ();
  void draw ();
  void setPixel (int, char);
};
