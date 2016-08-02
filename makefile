project5make: project5.cpp String.o
	g++ project5.cpp String.o -o project5make
String.o: String.h String.cpp
	g++ -c String.cpp
clean:
	rm *.o project5make
