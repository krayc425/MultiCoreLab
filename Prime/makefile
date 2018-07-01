all: prime


prime: main.o Prime.o
	g++ main.o Prime.o -o prime -lpthread -fopenmp


main.o: main.cpp
	g++ -c main.cpp -o main.o -lpthread -fopenmp


Prime.o: Prime.cpp
	g++ -c Prime.cpp -o Prime.o -lpthread -fopenmp


clean: 
	rm *.o
