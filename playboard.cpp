#include <iostream>
#include <sys/ioctl.h>
#include "playboard.h"
#include "keyboard-event.h"

Playboard::Playboard (int size):
  board(size) {
  reset();
}

int Playboard::size () {
  return board.size();
}

// re-initialise le board à son état initial
// (vide sans serpent si pomme)
void Playboard::reset () {
  for (auto &c: board)
    c = '.';
  board[0] = '[';
  board[board.size()-1] = ']';
}

void Playboard::clear () {
  backgroundClear();
  reset();
}

// permet d'écrire un caractère à une position du board
// sert à afficher des choses dans le board: serpent, pomme
void Playboard::setPixel (int x, char c) {
  board.at(x) = c;
}

// on dessine le board
void Playboard::draw () {
  for (auto &c: board)
    std::cout << c;
  std::cout << std::endl;
}

