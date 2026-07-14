linkStr: list.o itemString.o queueList.o main.o
	gcc list.o itemString.o queueList.o main.o -o queue.exe

list.o: 
	gcc -c list.c

itemString.o:
	gcc -c itemString.c

queueList.o:
	gcc -c queueList.c

main.o:
	gcc -c main.c

c:
	rm -f *.o *.exe

r:
	./queue.exe