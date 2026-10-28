DS_stack = ../../../../Data Structures/stack

sint: list.o main.o item_string.o stackList.o
	gcc list.o item_string.o main.o stackList.o -o stack.exe

stackList.o:
	gcc -c "$(DS_stack)/stackList.c" -o stackList.o

stackArray.o:
	gcc -c "$(DS_stack)/stackArray.c" -o stackArray.o

item_int.o:
	gcc -c "$(DS_stack)/item_int.c" -o item_int.o

item_string.o:
	gcc -c "$(DS_stack)/item_string.c" -o item_string.o

main.o:
	gcc -c main.c -o main.o

list.o:
	gcc -c "$(DS_stack)/list.c" -o list.o

c:
	rm -f *.o *.exe

r:
	./stack.exe