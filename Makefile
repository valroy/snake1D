CPP=g++
RM=rm -f

snake : snake.o playboard.o game.o main.o keyboard-event.o
	$(CPP) $^ -o $@

# vérifiez les dépendances
snake.o : snake.cpp snake.h playboard.h
playboard.o : playboard.cpp playboard.h keyboard-event.h
game.o : game.cpp game.h playboard.h snake.h

keyboard-event.o : keyboard-event.cpp keyboard-event.h
main.o : main.cpp game.h snake.h playboard.h

%.o:%.cpp
	$(CPP) -o $@ -c $<

clean:
	$(RM) *.o snake

.PHONY: clean
