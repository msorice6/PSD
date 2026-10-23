DS_queue = ../../../../Data Structures/queue
DS_stack = ../../../../Data Structures/stack
DS_list = ../../../../Data Structures/list

queue.exe: list.o item_string.o queueList.o stackList.o main.o
	gcc list.o item_string.o queueList.o stackList.o main.o -o queue.exe

item_string.o:
	gcc -c "$(DS_list)/item_string.c" -o item_string.o

queueList.o:
	gcc -c "$(DS_queue)/queueList.c" -o queueList.o

stackList.o:
	gcc -c "$(DS_stack)/stackList.c" -o stackList.o

main.o:
	gcc -c main.c

list.o:
	gcc -c "$(DS_list)/list.c" -o list.o

c:
	rm -f *.o *.exe

r:
	./queue.exe