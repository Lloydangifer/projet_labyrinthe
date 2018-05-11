#pragma once

#include "Position3D.h"
#include "Etage.h"

class Labyrinthe
{
public:
	Position3D position;
	Etage *etages[3];
	Labyrinthe(void);
	Labyrinthe(Position3D pos);
	~Labyrinthe(void);

	void dessiner_labyrinthe(void);
	void creer_etages(void);
};