#ifndef EVENT_H
#define EVENT_H

#include "packet.h"

class event{
	friend class LinkedList;
	private:
		unsigned int time;
		Packet* packetPtr;

	public:
		event(unsigned int time, Packet* packet);	//constructor prototype
		void print();
		bool operator< (const event& other) const;
		bool operator<= (const event& other) const;
		bool operator> (const event& other) const;
		bool operator>= (const event& other) const;
};

#endif
