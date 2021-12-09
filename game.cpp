#include <iostream>
#include "game.h"
#include <array>
#include "keyboard-event.h"

Game::Game(int size, int delay)
  : playboard(size),
    snake(size),
    delay(delay)
{}

void Game::play () {
  // le jeu est une boucle sans fin qu'on temporise de 'delay' ms
  // entre deux mouvements du serpent (on règle comme cela la vitesse
  // du serpent)

  // la clé entrée au clavier pour donner la direction du serpent ou
  // quitter le jeu (ou ce que vous voulez)
  char key = 'j'; // à gauche au début

  // par exemple, j'indique le mouvement du serpent par son décalage
  // en x (1 vers la droite et -1 vers la gauche)
  int dx {-1};
  
  while (true) {
    playboard.clear();
    snake.addToPlayboard(playboard);
    playboard.draw();
    sleepOneLap();

    if (keyEvent()) {
      std::cin >> key;
      // la clé key a été pressée
      if (key == 'l') // on veut aller à droite
	dx = 1; // donc décalage de 1
      else if (key == 'j') // on veut aller à gauche
	dx = -1; // donc décalage de -1
      else if (key == 'q') { // on quite la partie
	playboard.clear();
	std::cout << "see you soon little snake" << std::endl;
	exit(1);
      } else {
	// pas de clé (encore) connue: vous pouvez en rajouter pour de
	// nouveaux traitements
      }
    }
    // le serpent est entré dans un des murs
    if (not snake.goodMove(playboard, dx)) {
      std::cout << "game over" << std::endl;
      exit(2);
    }
  }
}

void Game::sleepOneLap() {
  clock_t end;
   end = clock() + delay * CLOCKS_PER_SEC / 1000;
  while (clock() < end)
    {
      // wait i.e. do nothing
    }
}
