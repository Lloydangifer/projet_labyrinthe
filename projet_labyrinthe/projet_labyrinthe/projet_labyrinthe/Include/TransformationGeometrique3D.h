#pragma once

#include "CoordonneesHomogenes3D.h"

class TransformationGeometrique3D
{
protected:
	double composantes[4][4];

public:
	TransformationGeometrique3D();
	TransformationGeometrique3D(double *t);
	TransformationGeometrique3D(double **t);
	TransformationGeometrique3D(TransformationGeometrique3D *tg);
	~TransformationGeometrique3D();

	void clear();

	void compose(TransformationGeometrique3D *tg);
	void compose(TransformationGeometrique3D *t1, TransformationGeometrique3D *t2);
	void transforme(CoordonneesHomogenes3D *ch);
};

