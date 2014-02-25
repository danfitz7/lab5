#ifndef EVENT_H
#define EVENT_H

#include "packet.h"

class event{
	private:
		unsigned int time;
		Packet* packetPtr;

	public:
		event(unsigned int time, Packet* packet);	//constructor prototype
		void print();
};

#endif
