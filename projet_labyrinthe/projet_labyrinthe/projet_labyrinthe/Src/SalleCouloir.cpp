#include "..\Include\SalleCouloir.h"

SalleCouloir::SalleCouloir(void):Salle()
{
	this->position = new Position3D();
}

SalleCouloir::SalleCouloir(Position3D pos):Salle()
{
	this->position = pos;
}

void SalleCouloir::dessiner_salle(void) {
	glPushMatrix();
	static const float blanc[] = { 1.0F, 1.0F, 1.0F, 1.0F };
	GLfloat shininess[] = { 50.0 };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, blanc);
	glMaterialfv(GL_FRONT, GL_SPECULAR, blanc);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	// sol
	this->dessiner_sol();
	//glPopMatrix();
	// mur de gauche
	//this->dessiner_mur();
	// mur de droite 
	glPopMatrix();
}