#include "..\Include\CoordonneesHomogenes3D.h"



CoordonneesHomogenes3D::CoordonneesHomogenes3D()
{
	composantes[0] = composantes[1] = composantes[2] = 0.0;
	composantes[3] = 1.0;
}

CoordonneesHomogenes3D::CoordonneesHomogenes3D(double x, double y, double z, double w)
{
	composantes[0] = x;
	composantes[1] = y;
	composantes[2] = z;
	composantes[3] = w;
}

CoordonneesHomogenes3D::CoordonneesHomogenes3D(double * c)
{
	this->composantes[0] = c[0];
	this->composantes[1] = c[1];
	this->composantes[2] = c[2];
	this->composantes[3] = c[3];
}

CoordonneesHomogenes3D::CoordonneesHomogenes3D(CoordonneesHomogenes3D * src)
{
	this->composantes[0] = src->composantes[0];
	this->composantes[1] = src->composantes[1];
	this->composantes[2] = src->composantes[2];
	this->composantes[3] = src->composantes[3];
}


CoordonneesHomogenes3D::~CoordonneesHomogenes3D()
{
}