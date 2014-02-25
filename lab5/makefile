##Start of the Makefile

lab5: main.o LinkedList.o event.o packet.o listNode.o
	g++ -o lab5 lab5.o event.o packet.o LinkedList.o listNode.o -I.
	
main.o: lab5.cpp lab5.h event.h packet.h lab5.h
	g++ -Wall -c lab5.cpp -I.
	
event.o: event.cpp event.h lab5.h packet.h lab5.h
	g++ -Wall -c event.cpp -I.
	
packet.o: packet.cpp lab5.h
	g++ -Wall -c packet.cpp -I.
	
listNode.o: listNode.cpp listNode.h lab5.h	
	g++ -Wall -c listNode.cpp -I.
	
LinkedList.o: LinkedList.cpp LinkedList.h listNode.h lab5.h
	g++ -Wall -c LinkedList.cpp -I.

clean:
	rm *.o
	
##End of the Makefile