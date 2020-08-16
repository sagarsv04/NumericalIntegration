# Make file for building application

CC = g++
CFLAGS = -std=c++11 -lpthread

integrate: integrate.o
	$(CC) integrate.o $(CFLAGS) -o integrate

integrate.o: integrate.cpp
	$(CC) -c integrate.cpp $(CFLAGS)

clean:
	rm -f *.o *.d integrate
