#pragma once

#include <GL/gl.h>
#include "Position3D.h"

class Salle {
public:
	Position3D position;
	float longueur = 10.0f;
	float largeur = 10.0f;
	Salle(void);
	Salle(Position3D pos);
	~Salle(void);

	virtual void dessiner_salle(void);
	void dessiner_sol(void);
	void dessiner_mur(void);
};