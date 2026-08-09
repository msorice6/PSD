DS_queue = ../../../../Data Structures/queue

queue.exe: list.o item_int.o queueList.o main.o
	gcc list.o item_int.o queueList.o main.o -o queue.exe

list.o:
	gcc -c "$(DS_queue)/list.c" -o list.o

item_int.o:
	gcc -c "$(DS_queue)/item_int.c" -o item_int.o

queueList.o:
	gcc -c "$(DS_queue)/queueList.c" -o queueList.o

main.o:
	gcc -c main.c -o main.o

c:
	rm -f *.o *.exe

r:
	./queue.exe