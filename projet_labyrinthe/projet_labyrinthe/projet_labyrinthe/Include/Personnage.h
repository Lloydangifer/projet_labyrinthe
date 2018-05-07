#pragma once

#include "Direction3D.h"

class Personnage {
public:
	Position3D position;
	Direction3D direction;
	double hauteur = 2.0;
	double angle;
	double facteur_vitesse; //modificateur de vitesse aux déplacements

	Personnage(void);
	Personnage(Position3D pos);
	~Personnage(void);

	Direction3D getDirection(void);
	Position3D getPosition(void);
	double getHauteur();

	void tourner(double angle);
	void avancer();
	void reculer();
};