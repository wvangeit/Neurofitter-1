/*
Revision of last commit: $Rev$
Author of last commit: $Author$
Date of last commit: $Date$
*/

#ifndef NEUROFITTER_GENESISMODELINTERFACE_H
#define NEUROFITTER_GENESISMODELINTERFACE_H

#include <vector> 
#include <fstream> 
using namespace std;

#include "ModelInterface.h"
#include "ExecutableModelInterface.h"
#include "FixedParamObject.h"

using namespace std;

class GenesisModelInterface : public ModelInterface, public FixedParamObject {

public:	
	GenesisModelInterface(TracesReader * t, FixedParameters params);
    virtual ModelResults runModel(const ModelTuningParameters &) ;
	virtual void runParallelModel(const vector< ModelTuningParameters >, vector< ModelResults > &);

private:
	ExecutableModelInterface execModel;
	GenesisModelInterface();
};

#endif
