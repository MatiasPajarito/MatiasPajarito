output: TreasureFinder.o Bomba.o Tablero.o Tierra.h
	gcc TreasureFinder.c Tierra.h  Bomba.o  Tablero.o  -o output

TreasureFinder.o: TreasureFinder.c
	gcc -c TreasureFinder.c

Bomba.o: Bomba.c Bomba.h
	gcc -c Bomba.c

Tablero.o: Tablero.c Tablero.h
	gcc -c Tablero.c

clean:
	rm *.o output