#include "..\Include\Labyrinthe.h"

Labyrinthe::Labyrinthe(void)
{
	this->position = new Position3D();
	this->creer_etages();
}

Labyrinthe::Labyrinthe(Position3D pos)
{
	this->position = pos;
	this->creer_etages();
}

Labyrinthe::~Labyrinthe(void)
{
}

void Labyrinthe::dessiner_labyrinthe(void)
{
	// on dessine le labyrinthe, etage par etage
	this->etages[0]->dessiner_etage();
	this->etages[1]->dessiner_etage();
	this->etages[2]->dessiner_etage();
}

void Labyrinthe::creer_etages(void)
{
	this->etages[0] = new Etage(this->position);
	this->etages[1] = new Etage(new Position3D(this->position.x(), this->position.y() + 4.0, this->position.z()));
	this->etages[2] = new Etage(new Position3D(this->position.x(), this->position.y() + 8.0, this->position.z()));
}
