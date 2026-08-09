int: list.o main.o item_int.o keyString.o entry.o hashtable.o itemEntrty.o
	gcc list.o item_int.o main.o keyString.o entry.o hashtable.o itemEntry.o -o hashtable.exe

string: list.o main.o item_string.o keyString.o entry.o hashtable.o itemEntry.o
	gcc list.o item_string.o main.o keyString.o entry.o hashtable.o itemEntry.o -o hashtable.exe

itemEntry.o:
	gcc -c itemEntry.c

keyString.o:
	gcc -c keyString.c

hashtable.o:
	gcc -c hashtable.c

entry.o:
	gcc -c entry.c

item_int.o:
	gcc -c item_int.c

item_string.o:
	gcc -c item_string.c

main.o:
	gcc -c main.c

list.o:
	gcc -c list.c

clean:
	rm -f *.o *.exe
