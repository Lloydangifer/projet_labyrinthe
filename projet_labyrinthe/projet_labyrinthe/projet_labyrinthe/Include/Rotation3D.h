#pragma once
#include "TransformationGeometrique3D.h"
#include "Direction3D.h"

#define _USE_MATH_DEFINES
#include <math.h>


class Rotation3D :
	public TransformationGeometrique3D
{
public:
	Rotation3D();
	Rotation3D(double angle, double ax, double ay, double az);

	~Rotation3D();
};

