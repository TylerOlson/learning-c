all: main.o fibonacci.o pointers.o
	g++ main.o fibonacci.o pointers.o -o yo
	make cleanbin

main.o: main.cpp
	g++ -g -c main.cpp

fibonacci.o: fibonacci.cpp fibonacci.h
	g++ -g -c fibonacci.cpp

pointers.o: pointers.cpp pointers.h
	g++ -g -c pointers.cpp

clean: cleanbin
	rm yo

cleanbin:
	rm *.o