linkInt: list.o itemString.o main.o
	gcc list.o itemString.o main.o -o list.exe

linkStr: list.o itemString.o main.o
	gcc list.o itemString.o main.o -o list.exe

list.o: 
	gcc -c list.c

itemInt.o:
	gcc -c itemInt.c

itemString.o:
	gcc -c itemString.c

main.o:
	gcc -c main.c

c:
	rm -f *.o *.exe

r:
	./list.exe