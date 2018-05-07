#include "..\Include\Personnage.h"
#include <stdio.h>

Personnage::Personnage(void)
{
	this->position = new Position3D();
	this->direction = new Direction3D(0.0,0.0,-1.0);
	this->angle = 0.0;
	this->facteur_vitesse = 0.003;
}

Personnage::Personnage(Position3D pos)
{
	this->position = pos;
	this->direction = new Direction3D(0.0, 0.0, -1.0);
	this->angle = 0.0;
	this->facteur_vitesse = 0.003;
}

Personnage::~Personnage(void)
{
}

Direction3D Personnage::getDirection(void)
{
	return this->direction;
}

Position3D Personnage::getPosition(void)
{
	return this->position;
}

double Personnage::getHauteur()
{
	return hauteur;
}

void Personnage::tourner(double angle)
{
	this->angle += angle;
	Rotation3D rotation(this->angle, 0.0, 1.0, 0.0);
	// On réinitialise la direction pour réappliquer la modification de la rotation
	// On pourrait faire une petite rotation en fonction des rotations précédentes, mais sur le long terme, on perd en précision
	// (Tout comme dans le constructeur, par défaut, la direction est orientée sur l'axe -Z)
	direction.set(0.0, 0.0, -1.0);
	rotation.transforme(&direction);
	printf("Je tourne. Direction: %d %d %d\n",direction.dx(),direction.dy(),direction.dz());
}

void Personnage::avancer()
{
	position.set(position.x() + (direction.dx()*facteur_vitesse), position.y(), position.z() + (direction.dz()*facteur_vitesse));
}

void Personnage::reculer()
{
	position.set(position.x() - (direction.dx()*facteur_vitesse), position.y(), position.z() - (direction.dz()*facteur_vitesse));
}
