#ifndef PACKET_H
#define PACKET_H

class Packet{
	private:
		unsigned int sentTime;
		unsigned int arrivalTime;
			
	public:
		Packet(unsigned int sentTime);
		void print();
};

#endif
