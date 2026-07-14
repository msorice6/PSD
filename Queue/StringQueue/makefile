queue.exe: item-string.o queue-array.o main.o
	gcc item-string.o queue-array.o main.o -o queue.exe

item-string.o:
	gcc -c item-string.c

queue-array.o:
	gcc -c queue-array.c

main.o:
	gcc -c main.c

c:
	rm *.o *.exe

r:
	./queue.exe