#pragma once
#include "playboard.h"

class Snake {
  int x;
  
public:
  
  Snake (int size);
  void addToPlayboard (Playboard&);
  bool goodMove (Playboard&, int dx);
};
