DS = ../../../../Data Structures/list

int: list.o main.o item_int.o
	gcc list.o item_int.o main.o -o list.exe

string: list.o main.o item_string.o
	gcc list.o item_string.o main.o -o list.exe

item_int.o:
	gcc -c "$(DS)/item_int.c" -o item_int.o

item_string.o:
	gcc -c "$(DS)/item_string.c" -o item_string.o
	
main.o:
	gcc -c main.c

list.o: 
	gcc -c "$(DS)/list.c" -o list.o

r:
	./list.exe

c:
	rm -f *.o *.exe