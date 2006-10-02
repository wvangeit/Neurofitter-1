#ifndef NEUROFITTER_H
#define NEUROFITTER_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

#include "DataTrace.h"
#include "XMLString.h"
#include "FixedParameters.h"

#include "TracesReader.h"
#include "NormalTracesReader.h"

#include "ModelTuningParameters.h"
#include "ModelResults.h"
#include "ExperimentInterface.h"
#include "ModelInterface.h"
#include "FitnessCalculator.h"
#include "FitterInterface.h"

#include "GenesisModelInterface.h"
#include "NeuronModelInterface.h"
#include "ExecutableModelInterface.h"
#include "FakeExperimentInterface.h"
#include "FileExperimentInterface.h"
#include "VdVdtMatrix.h"
#include "MapVdVdtMatrix.h"
#include "DirectVdVdtMatrix.h"
#include "DistanceVdVdtMatrix.h"
#include "MatrixFitnessCalculator.h"
#include "EasyFitterInterface.h"
#include "MeshFitterInterface.h"
#include "RandomFitterInterface.h"
#include "SwarmFitterInterface.h"

#ifdef WITH_EO
	#include "EOFitnessCalculator.h"
	#include "EOFitterInterface.h"
#endif

#ifdef WITH_NOMAD
	#include "NOMADFitterInterface.h"
#endif

#ifdef WITH_EO
	#ifdef WITH_NOMAD
		#include "EONOMADFitterInterface.h"
	#endif
#endif

#ifdef WITH_MPI
	#include <mpi.h>
	#include "MPIModelInterface.h"
	#include "MPIFitnessCalculator.h"
#endif

#endif
