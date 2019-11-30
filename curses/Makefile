CC  =g++
ARGS    =-Wall -std=c++17 -lncurses
TARGET  =hello
SOURCE  =main.cpp
TARGETO =main.o

all: $(TARGET)

$(TARGET): $(TARGETO)
	$(CC) -o $(TARGET) $(TARGETO) $(ARGS)

$(TARGETO): $(SOURCE)
	$(CC) -c $(SOURCE) $(ARGS)

clean :
	rm -f $(TARGETO) $(TARGET)
