CC = gcc 
FLAGS = -Wall -ansi -pedantic 
OBJ =   TurtleGraphics.o calc.o read.o effects.o cList.o 
EXEC = TurtleGraphics

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC) -lm 

calc.o: calc.c calc.h 
	$(CC) -c calc.c  $(CFLAGS)   

cList.o: cList.c cList.h
	$(CC) -c cList.c $(CFLAGS)  

effects.o: effects.c effects.h 
	$(CC) -c effects.c $(CLFAGS) 

read.o: read.c read.h cList.h
	$(CC) -c read.c   $(CFLAGS) 

TurtleGraphics.o: TurtleGraphics.c cList.h effects.h read.h calc.h
	$(CC) -c TurtleGraphics.c  $(CLFAGS) 

TurtleGraphicsSimple.o: TurtleGraphics.c cList.h effects.h read.h calc.h
	$(CC) -c TurtleGraphics.c  -D SIMPLE=1

TurtleGraphicsDebug.o: TurtleGraphics.c cList.h effects.h read.h calc.h
	$(CC) -c TurtleGraphics.c  -D DEBUG=1


clean:
	rm -f $(EXEC) $(OBJ)
