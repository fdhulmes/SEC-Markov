#a simple make file
#this file tells GNU make how to create the executable "the_world"
#this line declares that all targets for make will require "the_world"
all: markov_chain

#this line dictates that "the_world" relies on the four listed object files
markov_chain: markov.o markovLL.o markovNode.o
	g++ markov.o markovLL.o markovNode.o -o markov_chain

#this line gives a way of building main.o which relies on main.cpp
markov.o: markov.cpp
	g++ -c -g markov.cpp

#etc etc
markovLL.o: markovLL.cpp
	g++ -c -g markovLL.cpp
	
markovNode.o: markovNode.cpp
	g++ -c -g markovNode.cpp

#this gives a recipe for removing files ending in .o and the_world
clean:
	rm *.o markov_chain