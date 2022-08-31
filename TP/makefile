CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS =  $(OBJ)/main.o $(OBJ)/message.o $(OBJ)/BST.o $(OBJ)/hashTable.o 
HDRS = $(INC)/message.hpp $(INC)/BST.hpp  $(INC)/hashTable.hpp
CFLAGS = -pg -Wall -c -I$(INC)

EXE = $(BIN)/tp3

$(BIN)/tp3: $(OBJS)
	$(CC) -pg -o $(BIN)/tp3 $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/message.o: $(HDRS) $(SRC)/message.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/message.o $(SRC)/message.cpp

$(OBJ)/BST.o: $(HDRS) $(SRC)/BST.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/BST.o $(SRC)/BST.cpp

$(OBJ)/hashTable.o: $(HDRS) $(SRC)/hashTable.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/hashTable.o $(SRC)/hashTable.cpp

clean:
	rm -f $(EXE) $(OBJS) gmon.out