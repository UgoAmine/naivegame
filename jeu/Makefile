CC  =g++
ARGS    =-Wall -std=c++17 -lncurses
TARGET  =Board
SOURCE  =Board.cpp Joueur.cpp Monstre.cpp Element.cpp main.cpp
TARGETO =Board.o Joueur.o Monstre.o Element.o main.o

all: $(TARGET)

$(TARGET): $(TARGETO)
	$(CC) -o $(TARGET) $(TARGETO) $(ARGS)

$(TARGETO): $(SOURCE)
	$(CC) -c $(SOURCE) $(ARGS)

clean :
	rm -f $(TARGETO) $(TARGET)
