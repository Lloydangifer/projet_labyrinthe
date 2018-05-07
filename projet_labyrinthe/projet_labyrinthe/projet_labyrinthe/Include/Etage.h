#pragma once

#include "Position3D.h"
#include "Salle.h"

class Etage
{
public:
	Position3D position;
	int largeur = 5; // en nombre de salles
	int longueur = 5; // en nombre de salles
	int numero_etage;
	Salle salles[25];
	Etage(void);
	Etage(Position3D pos);
	Etage(Position3D pos, int num_etage);
	~Etage(void);
};