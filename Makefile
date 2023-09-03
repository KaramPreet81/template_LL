CC = g++
CFLAGS = -std=c++11 -Wall
SRC = camparsion.cpp
OBJS = single.o array.o
EXEC = main

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(SRC) $(OBJS) -o $(EXEC)

single.o: single.cpp
	$(CC) $(CFLAGS) -c single.cpp -o single.o

array.o: array.cpp
	$(CC) $(CFLAGS) -c array.cpp -o array.o

clean:
	rm -f $(OBJS) $(EXEC)

run: $(EXEC)
	./$(EXEC)
