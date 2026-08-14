DS_queue = ../../../../Data Structures/queue
DS_stack = ../../../../Data Structures/stack
DS_list = ../../../../Data Structures/list

linkStr: list.o itemInt.o queueList.o stackList.o main.o
	gcc list.o itemInt.o queueList.o stackList.o main.o -o queue.exe

list.o:
	gcc -c "$(DS_list)/list.c" -o list.o

itemInt.o:
	gcc -c "$(DS_list)/item_int.c" -o itemInt.o

queueList.o:
	gcc -c  "$(DS_queue)/queueList.c" -o queueList.o

stackList.o:
	gcc -c "$(DS_stack)/stackList.c" -o stackList.o

main.o:
	gcc -c main.c

c:
	rm -f *.o *.exe

r:
	./queue.exe