#include "..\Include\Translation3D.h"



Translation3D::Translation3D() : TransformationGeometrique3D()
{
}

Translation3D::Translation3D(Direction3D * dir) : Translation3D(dir->dx(), dir->dy(), dir->dz())
{
}

Translation3D::Translation3D(double tx, double ty, double tz)
{
	composantes[0][3] = tx;
	composantes[1][3] = ty;
	composantes[2][3] = tz;
}


Translation3D::~Translation3D()
{
}
