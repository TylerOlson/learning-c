all: main.o fibonacci.o
	g++ main.o fibonacci.o -o yo
	make cleanbin

main.o: main.cpp
	g++ -g -c main.cpp

fibonacci.o: fibonacci.cpp fibonacci.h
	g++ -g -c fibonacci.cpp

clean: cleanbin
	rm yo

cleanbin:
	rm *.o