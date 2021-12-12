#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <string.h>

using namespace std;

#ifndef STP
#define STP


class Frame {

protected:

	char* Header_;
	char* Payload_;


public:

	Frame(char* header, char* payload) {
		this->Header_ = header;
		this->Payload_ = payload;
	}

	virtual ~Frame();

	virtual char* Serialize();

	static Frame Parse(iostream s);

};

class BPDU : public Frame {

private:

	static char* SpanningTreeID = 0x0000; //protocol id
	static char* Configuration = 0x00; //message type


	char* ProtocolID_;
	int ProtocolVersionID_;
	int BPDUType_;
	char* Flags_;
	char* RootID_;
	int RootPathCost_;
	char* BridgeID_;
	char* PortID_;

	ushort MessageAge_;
	ushort MaxAge_;
	ushort HelloTime_;
	ushort ForwardDelay_;


public:

	BPDU(char* protocolID = SpanningTreeID, int version = 0, int BPDUType = Configuration, char* flags = 0x01, char* rootID = 0,
			int rootPathCost = 0, char* bridgeID = 0, char* portID = 0, ushort messageAge = 0, ushort maxAge = 20,
			ushort helloTime = 2, ushort forwardDelay = 15) {

		this->ProtocolID_ = this->SpanningTreeID;
		this->ProtocolVersionID_ = version;
		this->BPDUType_ = BPDUType;
		this->Flags_ = flags;
		this->RootID_ = rootID;
		this->RootPathCost_ = rootPathCost;
		this->BridgeID_ = bridgeID;
		this->PortID_ = portID;
		this->MessageAge_ = messageAge;
		this->MaxAge_ = maxAge;
		this->HelloTime_ = helloTime;
		this->ForwardDelay_ = forwardDelay;
	}

	char* Serialize() override;

	static BPDU Parse(iostream s);

};

#endif
