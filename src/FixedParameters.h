/*
Revision of last commit: $Rev$
Author of last commit: $Author$
Date of last commit: $Date$
*/

#ifndef NEUROFITTER_FIXEDPARAMETERS_H
#define NEUROFITTER_FIXEDPARAMETERS_H

#include <map>
#include <string>

using namespace std;

#include "XMLString.h"

using namespace std;

class FixedParameters {

	public:
		FixedParameters() {};
		FixedParameters(string parameters, bool isGlobal = false);
		FixedParameters(string parameters, string globalparameters);

		string& operator[](const string index);
		const string&operator[](const string index) const;

		string getGlobals() const;

		void readFromXML(string parameters, bool global);

		void addParameter(const string index, const string value, const bool isGlobal = false);
		void removeParameter(const string index);

		bool parameterExists(const string index) const; 

		void setGlobal(string);
		void notGlobal(string);
		bool getGlobal(string);

		string getProp(string);

		string toString() const;	
	private:
		map< string, pair< string,bool > > params;

};

#endif
