stack.exe: item-string.o stack.o main.o
	gcc item-string.o stack.o main.o -o stack.exe

item-string.o:
	gcc -c item-string.c

stack.o:
	gcc -c stack.c

main.o:
	gcc -c main.c

c:
	rm *.o *.exe

r:
	./stack.exe