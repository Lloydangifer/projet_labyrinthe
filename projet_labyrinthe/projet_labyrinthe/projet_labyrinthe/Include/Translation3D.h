#pragma once
#include "TransformationGeometrique3D.h"
#include "Direction3D.h"

class Translation3D :
	public TransformationGeometrique3D
{
public:
	Translation3D();
	Translation3D(Direction3D * dir);
	Translation3D(double tx, double ty, double tz);

	~Translation3D();
};

