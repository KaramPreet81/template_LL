CC = g++
CFLAGS = -std=c++11 -Wall
SRC = camparsion.cpp
OBJS = single.o array.o
EXEC = camparsion

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(SRC) $(OBJS) -o $(EXEC)

single.o: single.cpp
	$(CC) $(CFLAGS) -c templatebased.cpp -o single.o

array.o: array.cpp
	$(CC) $(CFLAGS) -c templatebased.cpp -o array.o

clean:
	rm -f $(OBJS) $(EXEC)

run: $(EXEC)
	./$(EXEC)
