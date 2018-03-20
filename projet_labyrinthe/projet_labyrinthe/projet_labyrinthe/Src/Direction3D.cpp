#include "..\Include\Direction3D.h"



Direction3D::Direction3D(void):CoordonneesHomogenes3D(0.0,0.0,0.0,0.0)
{
}

Direction3D::Direction3D(double x, double y, double z):CoordonneesHomogenes3D(x,y,z,0.0)
{
}

Direction3D::Direction3D(double * c):CoordonneesHomogenes3D(c)
{
}

Direction3D::Direction3D(Direction3D * p):CoordonneesHomogenes3D(p)
{
}

Direction3D::Direction3D(Position3D * p1, Position3D * p2)
{
	composantes[0] = p1->composantes[0] - p2->composantes[0];
	composantes[1] = p1->composantes[1] - p2->composantes[1];
	composantes[2] = p1->composantes[2] - p2->composantes[2];
	composantes[3] = 0.0;
}

double Direction3D::produitScalaire(Direction3D *d) {
	return(composantes[0] * d->composantes[0] + composantes[1] * d->composantes[1] + composantes[2] * d->composantes[2]);
}

void Direction3D::produitVectoriel(Direction3D * d)
{
	produitVectoriel(this, d);
}

void Direction3D::produitVectoriel(Direction3D * d1, Direction3D * d2)
{
	double x = d1->composantes[1]*d2->composantes[2] - d1->composantes[2]*d2->composantes[1];
	double y = d1->composantes[2]*d2->composantes[0] - d1->composantes[0]*d2->composantes[2];
	double z = d1->composantes[0]*d2->composantes[1] - d1->composantes[1]*d2->composantes[0];
	composantes[3] = 0.0;
	composantes[0] = x;
	composantes[1] = y;
	composantes[2] = z;
}

Direction3D::~Direction3D(void)
{
}

double Direction3D::dx(void)
{
	return composantes[0];
}

double Direction3D::dy(void)
{
	return composantes[1];
}

double Direction3D::dz(void)
{
	return composantes[2];
}

double Direction3D::dw(void)
{
	return composantes[3];
}

void Direction3D::set(Direction3D * dir)
{
	composantes[0] = dir->dx();
	composantes[1] = dir->dy();
	composantes[2] = dir->dz();
}

void Direction3D::set(double dx, double dy, double dz)
{
	composantes[0] = dx;
	composantes[1] = dy;
	composantes[2] = dz;
}

double Direction3D::norme(void)
{
	return sqrt(composantes[0] * composantes[0] + composantes[1] * composantes[1] + composantes[2] * composantes[2]);
}

double Direction3D::normalisation(void)
{
	double d = norme();
	if (d != 0.0) {
		composantes[0] /= d;
		composantes[1] /= d;
		composantes[2] /= d;
	}
	return d;
}

void Direction3D::tourner(double angle, double x, double y, double z)
{
	TransformationGeometrique3D tg = TransformationGeometrique3D();
	Direction3D d = Direction3D(this);
	tg.compose(&Translation3D(&-d), &Rotation3D(angle, x, y, z));
	tg.compose(&Translation3D(&d));
	tg.transforme(this);
}

Direction3D Direction3D::operator-()
{
	return Direction3D(-composantes[0], -composantes[1], -composantes[2]);
}

Direction3D Direction3D::operator/(double diviseur)
{
	return Direction3D(composantes[0] / diviseur, composantes[1] / diviseur, composantes[2] / diviseur);
}