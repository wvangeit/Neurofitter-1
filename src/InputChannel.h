/*
Revision of last commit: $Rev$
Author of last commit: $Author$
Date of last commit: $Date$
*/

#ifndef NEUROFITTER_INPUTCHANNEL_H
#define NEUROFITTER_INPUTCHANNEL_H

#include <string>

using namespace std;

class InputChannel {

	public:
		virtual InputChannel &operator>>(bool &) = 0;
		virtual InputChannel &operator>>(int &) = 0;
		virtual InputChannel &operator>>(unsigned &) = 0;
		virtual InputChannel &operator>>(string &) = 0;
		virtual InputChannel &operator>>(float &) = 0;
		virtual InputChannel &operator>>(double &) = 0;
		virtual ~InputChannel() {};	      
};

#endif
