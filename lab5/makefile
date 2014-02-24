##Start of the Makefile

lab5: main.o linkedList.o event.o packet.o
	g++ -o lab5 lab5.o event.o packet.o -I.
	
main.o: lab5.cpp lab5.h event.h packet.h
	g++ -Wall -c lab5.cpp -I.

event.o: event.cpp event.h lab5.h packet.h
	g++ -Wall -c event.cpp -I.
	
packet.o: packet.cpp lab5.h
	g++ -Wall -c packet.cpp -I.

clean:
	rm *.o
	
##End of the Makefile