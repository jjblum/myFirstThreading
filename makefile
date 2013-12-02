C = CThread
LXX += -L/usr/local/lib
LXX += -lSDL

all: clean threadTEST  
#putting clean first here b/c threading gets funky if all objects aren't compiled together all at once

threadTEST: main.o $(C).o $(C)_Add.o
	g++ main.o $(C).o $(C)_Add.o -o threadTEST $(LXX)
	
main.o: main.cpp
	g++ -c -Wall main.cpp
	
$(C).o: $(C).cpp
	g++ -c -Wall $(C).cpp 
	
$(C)_Add.o: $(C)_Add.cpp
	g++ -c -Wall $(C)_Add.cpp
	
clean:
	rm -rf *.o threadTEST
