/*
Revision of last commit: $Rev$
Author of last commit: $Author$
Date of last commit: $Date$
*/

#ifndef NEUROFITTER_DATATRACE_H
#define NEUROFITTER_DATATRACE_H

#include <string>
#include <vector>
#include <iostream>

#include "Tools.h"

#include "InputChannel.h"
#include "OutputChannel.h"

using namespace std;

class DataTrace {

public:
	DataTrace();
	DataTrace(const int size); 

	int getLength() const;
	int getValidLength() const;

	double getWeight() const;
	double getStartTime() const;
	double getStopTime() const;
	double getSamplingFrequency() const;
	int getLag() const;
	double getLagWeight() const;

	int getRun() const;
	int getNumberOfRuns() const;
	int getPeriod() const;
	int getNumberOfPeriods() const;
	int getRecordingSite() const;
	int getNumberOfRecordingSites() const;

	string getName() const;

	void setWeight(const double);
	void setStartTime(const double);
	void setStopTime(const double);
	void setSamplingFrequency(const double);
	void setName(const string);
	void setLag(const int lag, const double weight);
	void setRun(const int);
	void setNumberOfRuns(const int);
	void setPeriod(const int);
	void setNumberOfPeriods(const int);
	void setRecordingSite(const int);
	void setNumberOfRecordingSites(const int);

	void resetAndSetLength(const int);

	void printOn(OutputChannel &) const;
	void readFrom(InputChannel &);

	bool pointIsValid(const int) const;

	double get(const int t) const;
	void set(const int t, const double value);

protected:
	vector< pair< double, bool > > points;
	
	double weight;
	double startTime;
	double stopTime;
	double samplingFrequency;

	int lag;
	double lagWeight;

	int run;
	int numberOfRuns;
	int period;
	int numberOfPeriods;
	int recordingSite;
	int numberOfRecordingSites;

	int validLength;

	string name;
};

#endif
