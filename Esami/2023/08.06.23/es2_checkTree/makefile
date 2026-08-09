# Define the relative paths to the Data Structures directories
DS_BTREE = ../../../../Data Structures/btree
DS_LIST = ../../../../Data Structures/list

btree.exe: btree.o item-int.o list.o main.o
	gcc btree.o item-int.o list.o main.o -o btree.exe

btree.o:
	gcc -c "$(DS_BTREE)/btree.c" -o btree.o

item-int.o:
	gcc -c "$(DS_BTREE)/item-int.c" -o item-int.o

list.o:
	gcc -c "$(DS_LIST)/list.c" -o list.o

main.o: main.c
	gcc -c main.c

c:
	rm -f *.o *.exe

r:
	./btree.exe