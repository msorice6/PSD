btree.exe: btree.o item-int.o list.o main.o
	gcc btree.o item-int.o list.o main.o -o btree.exe

btree.o: btree.c
	gcc -c btree.c

item-int.o: item-int.c
	gcc -c item-int.c

list.o: list.c
	gcc -c list.c

main.o: main.c
	gcc -c main.c

c:
	rm *.o *.exe

r:
	./btree.exe