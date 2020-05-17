main: funkcijos.o Studentas.o main.o
	g++ -Wall -o  main main.cpp funkcijos.cpp Studentas.cpp 
test: 
	g++ -o testas testai/testukas.cpp Studentas.cpp -lgtest -lpthread
clean:
	rm *.o *.txt main testas
