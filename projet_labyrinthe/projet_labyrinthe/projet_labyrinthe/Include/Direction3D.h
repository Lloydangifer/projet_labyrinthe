#pragma once
#include "CoordonneesHomogenes3D.h"
#include "Position3D.h"
#include "Rotation3D.h"
#include "Translation3D.h"


#define _USE_MATH_DEFINES
#include <math.h>

class Direction3D :
	public CoordonneesHomogenes3D
{
public:
	Direction3D(void);
	Direction3D(double x, double y, double z);
	Direction3D(double *c);
	Direction3D(Direction3D *p);
	Direction3D(Position3D *p1, Position3D *p2);
	double produitScalaire(Direction3D *d);
	void produitVectoriel(Direction3D *d);
	void produitVectoriel(Direction3D *d1, Direction3D *d2);
	~Direction3D(void);

	double dx(void);
	double dy(void);
	double dz(void);
	double dw(void);

	void set(Direction3D * dir);
	void set(double dx, double dy, double dz);

	double norme(void);

	double normalisation(void);

	// Si on considère la direction comme un vecteur : effectue une rotation par rapport à son point de départ
	void tourner(double angle, double x, double y, double z);

	Direction3D operator-();
	Direction3D operator/(double diviseur);

};

