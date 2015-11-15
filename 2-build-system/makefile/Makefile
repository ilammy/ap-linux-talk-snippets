all: hello

hello: main.o hello.o
	g++ -o hello main.o hello.o

main.o: main.c hello.h
	gcc -c main.c

hello.o: hello.cpp hello.h
	g++ -c hello.cpp

clean:
	rm *.o
	rm hello
