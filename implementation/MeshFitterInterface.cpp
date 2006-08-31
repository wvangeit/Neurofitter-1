#include "../MeshFitterInterface.h"

FitterResults MeshFitterInterface::runFitter(ModelTuningParameters * unusedStartPoint) {

	ModelTuningParameters resolution(fixedParams["MeshSize"],toInt(fixedParams["Dimensions"]),fixedParams["Bounds"]);

	if (toInt(fixedParams["VerboseLevel"]) > 4) {
		cout << "Creating MeshInterface with " << toInt(fixedParams["Dimensions"]) << " dimensions" << endl;
	}

	vector< ModelTuningParameters > mesh;


	ModelTuningParameters currentPoint("",toInt(fixedParams["Dimensions"]),fixedParams["Bounds"]);

	calculateMesh(0,resolution,currentPoint, mesh);

	fitness->calculateParallelFitness(mesh);

	return FitterResults();
}

void MeshFitterInterface::calculateMesh(int startDimension, ModelTuningParameters & resolution, ModelTuningParameters & currentPoint, vector< ModelTuningParameters > & mesh ) {

	if (startDimension == toInt(fixedParams["MeshDimensions"])) {
		mesh.push_back(currentPoint);
	}
	else {
		currentPoint[startDimension] = resolution.getLowerBound(startDimension);  
		double dx = (resolution.getUpperBound(startDimension)-resolution.getLowerBound(startDimension))/(resolution[startDimension]-1);

		//"Smaller than or equal" to include upperbound
		for (int i = 0; i <= resolution[startDimension]-1; i++) {
			calculateMesh(startDimension+1,resolution,currentPoint,mesh);
			currentPoint[startDimension] += dx; 
    	}
	}
}
