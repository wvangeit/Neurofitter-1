#ifndef MODELINTERFACE_H
#define MODELINTERFACE_H

#include "ModelResults.h"
#include "ModelTuningParameters.h"

using namespace std;

class ModelInterface {

public:

	virtual ModelResults runModel(const ModelTuningParameters &) const = 0;
//	virtual void readFixedParameters(const string);
	virtual ~ModelInterface() {};

private:	


};

#endif
