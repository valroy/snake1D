#include "snake.h"

Snake::Snake(int size) : x(size/2) {
}

void Snake::addToPlayboard (Playboard& playboard) {
  playboard.setPixel(x, 'O');
}

bool Snake::goodMove (Playboard& pl, int dx) {
  x+=dx;
  if ((x <= 0) or (x >= pl.size()-1))
    return false;
  return true;
}
