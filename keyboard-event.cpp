#include <iostream>
#include <sys/ioctl.h>
#include <termios.h>
#include <cstdio>
#include <ctime>

static const int STDIN = 0;
static bool initialized = false;

void backgroundClear() {
  int out = system("clear");
  if (out != 0) {
    std::cerr << "clear command failed" << std::endl;
    exit(3);
  }
}

int keyEvent()
{
  // lit des caractères dans un terminal pour faire bouger le serpent

  if (!initialized)
  {
    // en premier (et une seule fois par exécution) on inialise un
    // terminal

    // termios est une API qui permet de manipuler dans votre
    // programme, des entrées/sorties faites dans un terminal

    // création d'un terminal
    termios term;

    // la fonction tcgetattr permet d'initialiser des paramètres de cette API

    // là on demande que l'entrée standard STDIN (on est en c) soit
    // notre terminal i.e. quand on va taper un caractère sur notre
    // terminal STDIN recevra ce caractère
    tcgetattr(STDIN, &term);

    // là on met à faux le mode ICANON pour le terminal term (Input
    // CANnonical mode ON)

    // en gros on demande de ne pas lire une ligne de caractère (qui se
    // terminerait donc au retour-à-la-ligne) mais un seul caractère
    // (pour faire bouger le serpent)
    term.c_lflag &= ~ICANON;

    // on demande à ce que la configuration soit prise en compte
    // innmédiatement pour le terminal
    tcsetattr(STDIN, TCSANOW, &term);

    // les entrées ne seront pas bufferisées
    setbuf(stdin, NULL);

    // on a fini d'initialiser, au prochain appel de cette fonction,
    // on ne refera plus cette initialisation
    initialized = true;
  }
  int bytesWaiting;
  // int bytesWaiting;

  // la requête pour lire sur notre terminal désormais notre STDIN
  // et stocker le caractère lu dans la mémoire bytesWaiting
  ioctl(STDIN, FIONREAD, &bytesWaiting);
  return bytesWaiting;
}

void sleepOneLap(const int ms)
{
  clock_t end;
  // on initialise la quantité de temps à attendre
  end = clock() + ms * CLOCKS_PER_SEC / 1000;
  while (clock() < end)
  {
    // wait i.e. do nothing
  }
}
