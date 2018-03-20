#include "..\Include\Position3D.h"
#include "..\Include\Direction3D.h"
#include <stdio.h>


Position3D::Position3D():CoordonneesHomogenes3D()
{
}

Position3D::Position3D(double x, double y, double z):CoordonneesHomogenes3D(x,y,z, 1.0)
{
}

Position3D::Position3D(double * c):CoordonneesHomogenes3D(c)
{
}

Position3D::Position3D(Position3D * p): CoordonneesHomogenes3D(p)
{
}

Position3D::~Position3D()
{
}

double Position3D::x(void)
{
	return composantes[0];
}

double Position3D::y(void)
{
	return composantes[1];
}

double Position3D::z(void)
{
	return composantes[2];
}

double Position3D::w(void)
{
	return composantes[3];
}

void Position3D::set(Position3D * pos)
{
	composantes[0] = pos->x();
	composantes[1] = pos->y();
	composantes[2] = pos->z();
}

void Position3D::set(double x, double y, double z)
{
	composantes[0] = x;
	composantes[1] = y;
	composantes[2] = z;
}

void Position3D::translater(Direction3D direction)
{
	composantes[0] = composantes[0] + direction.dx();
	composantes[1] = composantes[1] + direction.dy();
	composantes[2] = composantes[2] + direction.dz();
}
