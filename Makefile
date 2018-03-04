output: main.o Menu.o InputValidation.o HelperFunctions.o
	g++ -std=c++0x -g -Wall -pedantic-errors main.o Menu.o InputValidation.o HelperFunctions.o -o lab8

main.o: main.cpp
	g++ -std=c++0x -g -Wall -pedantic-errors -c main.cpp

Menu.o: Menu.cpp
	g++ -std=c++0x -g -Wall -pedantic-errors -c Menu.cpp

InputValidation.o: InputValidation.cpp
	g++ -std=c++0x -g -Wall -pedantic-errors -c InputValidation.cpp

HelperFunctions.o: HelperFunctions.cpp
	g++ -std=c++0x -g -Wall -pedantic-errors -c HelperFunctions.cpp

clean:
	rm *.o lab8