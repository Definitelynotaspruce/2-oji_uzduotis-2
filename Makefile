main: funkcijos.o Studentas.o main.o 
	g++ -Wall -o  main main.cpp funkcijos.cpp Studentas.cpp -std=c++17
test: 
	g++ -o testas testai/testukas.cpp Studentas.cpp -std=c++17 -lgtest -lpthread
clean:
	rm *.o *.txt main testas
