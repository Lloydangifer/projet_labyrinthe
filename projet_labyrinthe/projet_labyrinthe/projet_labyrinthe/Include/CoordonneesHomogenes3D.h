#pragma once
class CoordonneesHomogenes3D
{
public:
	double composantes[4];
	CoordonneesHomogenes3D(void);
	CoordonneesHomogenes3D(double x, double y, double z, double w);
	CoordonneesHomogenes3D(double *c);
	CoordonneesHomogenes3D(CoordonneesHomogenes3D *src);
	~CoordonneesHomogenes3D(void);
};

