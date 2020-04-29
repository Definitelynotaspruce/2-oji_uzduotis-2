main: funkcijos.o Studentas.o main.o
	g++ -Wall -o main main.cpp funkcijos.cpp Studentas.cpp 
clean:
	rm *.o *.txt main
