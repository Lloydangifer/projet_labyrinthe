#include "..\Include\Rotation3D.h"



Rotation3D::Rotation3D() : TransformationGeometrique3D()
{
}

Rotation3D::Rotation3D(double angle, double ax, double ay, double az)
{
	Direction3D v(ax, ay, az);
	v.normalisation();
	double aa = angle / 180.0*M_PI;
	float sn = (float)sin(aa);
	float cs = (float)cos(aa);
	composantes[0][0] = v.composantes[0] * v.composantes[0] + cs*(1 - v.composantes[0] * v.composantes[0]);
	composantes[0][1] = v.composantes[0] * v.composantes[1] * (1 - cs) - sn*v.composantes[2];
	composantes[0][2] = v.composantes[0] * v.composantes[2] * (1 - cs) + sn*v.composantes[1];
	composantes[1][0] = v.composantes[0] * v.composantes[1] * (1 - cs) + sn*v.composantes[2];
	composantes[1][1] = v.composantes[1] * v.composantes[1] + cs*(1 - v.composantes[1] * v.composantes[1]);
	composantes[1][2] = v.composantes[1] * v.composantes[2] * (1 - cs) - sn*v.composantes[0];
	composantes[2][0] = v.composantes[0] * v.composantes[2] * (1 - cs) - sn*v.composantes[1];
	composantes[2][1] = v.composantes[1] * v.composantes[2] * (1 - cs) + sn*v.composantes[0];
	composantes[2][2] = v.composantes[2] * v.composantes[2] + cs*(1 - v.composantes[2] * v.composantes[2]);
}


Rotation3D::~Rotation3D()
{
}
