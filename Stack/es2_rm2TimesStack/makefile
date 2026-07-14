string: list.o main.o item_string.o stackArray.o
	gcc list.o item_string.o main.o stackArray.o -o stack.exe

stackList.o:
	gcc -c stackList.c

stackArray.o:
	gcc -c stackArray.c

item_string.o:
	gcc -c item_string.c
	
main.o:
	gcc -c main.c

list.o: 
	gcc -c list.c

c:
	rm -f *.o *.exe

r:
	./stack.exe