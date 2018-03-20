#pragma once
#include "CoordonneesHomogenes3D.h"


class Direction3D;


class Position3D :
	public CoordonneesHomogenes3D
{
public:
	Position3D(void);
	Position3D(double x, double y, double z);
	Position3D(double *c);
	Position3D(Position3D *p);
	~Position3D();


	double x(void);
	double y(void);
	double z(void);
	double w(void);

	void set(Position3D * pos);
	void set(double x, double y, double z);

	/* Translate la position suivant la Direction3D donnée en paramètre */
	void translater(Direction3D direction);
};

