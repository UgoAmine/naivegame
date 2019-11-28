CC  =g++
ARGS    =-Wall -std=c++17
TARGET  =Board
SOURCE  =Board.cpp main.cpp
TARGETO =Board.o main.o

all: $(TARGET)

$(TARGET): $(TARGETO)
	$(CC) $(ARGS) -o $(TARGET) $(TARGETO)

$(TARGETO): $(SOURCE)
	$(CC) $(ARGS) -c $(SOURCE)

clean :
	rm -f $(TARGETO) $(TARGET)
