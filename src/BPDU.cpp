//============================================================================
// Name        : BPDU.cpp
// Date		   : 6/12/21
// Author      : Kazute
// Description : Spanning Tree protocol implementation in C/C++
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Stp.h"

using namespace std;

/*Generic Frame*/

char* Frame::Serialize() {

	int length = strlen(Frame::Header_) + strlen(Frame::Payload_) + 1;
	char* fullFrame = malloc(length);
	strcpy(fullFrame, Frame::Header_);
	strcat(fullFrame, Frame::Payload_);

	return fullFrame;
}


/*BPDU Frame*/


char* BPDU::Serialize() {


}

static BPDU BPDU::Parse(iostream s) {

	//get length
	s.seekg(0, s.end);
	int length = s.tellg();
	s.seekg(0, s.beg);

	//read data

	char *protocolID = new char[2];
	s.read(protocolID, 2);

	char *versionID = new char[1];
	s.read(versionID, 2);

	char *BPDUType = new char[1];
	s.read(BPDUType, 1);

	char *flags = new char[1];
	s.read(flags, 1);

	char *rootID = new char[8];
	s.read(rootID, 8);

	char *rootPathCost = new char[4];
	s.read(rootPathCost, 4);

	char *bridgeID = new char[8];
	s.read(bridgeID, 8);

	char *portID = new char[2];
	s.read(portID, 2);

	char *messageAge = new char[2];
	s.read(messageAge, 2);

	char *maxAge = new char[2];
	s.read(maxAge, 2);

	char *helloTime = new char[2];
	s.read(helloTime, 2);

	char *delay = new char[2];
	s.read(delay, 2);

	if(s.tellg() != length) {
		cerr << "Did not reach end of stream" << endl;
	}

	return BPDU(protocolID, (int)versionID, (int)BPDUType, flags, rootID, (int)rootPathCost, bridgeID,
			portID, (short)messageAge, (short)maxAge, (short)helloTime, (short)delay);

}


int main() {

	//add main code here
  //eg
	BPDU BPDU_frame = BPDU();
	return 0;
}
