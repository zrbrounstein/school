project11: main_driver.cpp arraylist.o nodelist.o fibonacci.o
	g++ -g main_driver.cpp arraylist.o nodelist.o fibonacci.o -o project11
arraylist.o: alist.h arraylist.cpp
	g++ -g -c arraylist.cpp
nodelist.o: nlist.h nodelist.cpp
	g++ -g -c nodelist.cpp
fibonacci.o: fibonacci.h fibonacci.cpp
	g++ -g -c fibonacci.cpp
clean:
	rm *.o project11
