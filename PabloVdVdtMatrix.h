#ifndef PABLOVDVDTMATRIX_H
#define PABLOVDVDTMATRIX_H

#include <iostream>
#include <cmath>

using namespace std;

#include "DataTrace.h"
#include "FixedParamObject.h"
#include "Tools.h"

///todo use a map to implement this
class PabloVdVdtMatrix : public FixedParamObject {

public:
	PabloVdVdtMatrix();
	PabloVdVdtMatrix(FixedParameters);
	PabloVdVdtMatrix(const DataTrace&, FixedParameters);
	//PabloVdVdtMatrix(const PabloVdVdtMatrix & v) {*this = v;}; 
	
	//PabloVdVdtMatrix& operator=(const PabloVdVdtMatrix&);

	//~PabloVdVdtMatrix();

	int getVLength() const;
	int getdVdtLength() const;

	inline vector<double>& operator[](const int);
	inline const vector<double>& operator[](const int) const;

	double compare(const PabloVdVdtMatrix&) const;

	string toString() const;
	
private:
	int vLength;
	int dVdtLength;	
	vector< vector< double > > VdVdtMatrix;
};
	
#endif
