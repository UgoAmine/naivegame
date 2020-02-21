CC  	= g++
ARGS    = -Wall -Wextra -std=c++17 -lncurses -lstdc++fs
TARGET  = Jeu
SOURCE  = Board.cpp Element.cpp Mobile.cpp Joueur.cpp main.cpp Jeu.cpp
TARGETO = Board.o Element.o Mobile.o Joueur.o main.o Jeu.o

all: $(TARGET)

$(TARGET): $(TARGETO)
	$(CC) -o $(TARGET) $(TARGETO) $(ARGS)

$(TARGETO): $(SOURCE)
	$(CC) -c $(SOURCE) $(ARGS)

clean :
	rm -f $(TARGETO) $(TARGET)
