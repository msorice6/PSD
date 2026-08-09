DS_queue = ../../../../Data Structures/queue

linkStr: list.o itemString.o queueList.o main.o
	gcc list.o itemString.o queueList.o main.o -o queue.exe

list.o:
	gcc -c "$(DS_queue)/list.c" -o list.o

itemString.o:
	gcc -c "$(DS_queue)/item_string.c" -o itemString.o

queueList.o:
	gcc -c  "$(DS_queue)/queueList.c" -o queueList.o

main.o:
	gcc -c main.c

c:
	rm -f *.o *.exe

r:
	./queue.exe