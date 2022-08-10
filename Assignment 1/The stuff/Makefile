
output: main.o message.o
	g++ main.o message.o -o output

main.o: main.cpp
	g++ -c main.cpp

message.0: message.cpp message.h
	g++ -c message.cpp

target: dependencies
	action