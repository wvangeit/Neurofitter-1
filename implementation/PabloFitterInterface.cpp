#include "../PabloFitterInterface.h"

PabloFitterInterface::PabloFitterInterface(FitnessCalculator * fit, FixedParameters param) 
	: FitterInterface(fit), FixedParamObject(param) {}

FitterResults PabloFitterInterface::runFitter(ModelTuningParameters * startPoints) {
	///////////////////////
	/// Read parameters ///
	///////////////////////
 
	FixedParameters eoFixParam = FixedParameters(fixedParams["EOFitterParameters"], fixedParams.getGlobals());
	FixedParameters nomadFixParam = FixedParameters(fixedParams["NOMADFitterParameters"], fixedParams.getGlobals());

	//////////////
	/// Run EO ///
	//////////////
	EOFitterInterface eo(fitness, eoFixParam);
	ModelTuningParameters eoBest = (eo.runFitter(startPoints)).getBestFit();

	cout << endl << "Best solution found by EO: "<< eoBest.toString() << endl;

	//////////////////////////////////////////
	/// Run NOMAD with best solution of EO ///
	//////////////////////////////////////////
	NOMADFitterInterface nomad(fitness, nomadFixParam);
    nomad.runFitter(&eoBest);

	return FitterResults();
}
