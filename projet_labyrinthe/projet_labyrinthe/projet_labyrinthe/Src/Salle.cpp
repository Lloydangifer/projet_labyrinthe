#include "..\Include\Salle.h"

Salle::Salle(void)
{
}

Salle::Salle(Position3D pos)
{
}

Salle::~Salle(void)
{
}

void Salle::dessiner_salle(void)
{
}

void Salle::dessiner_sol(void)
{
	glPushMatrix();
	glBegin(GL_QUADS);
	glNormal3f(0.0, 1.0, 0.0);
	glVertex3f(-(longueur / 2.0f), 0.0f, -(largeur / 2.0f));
	glVertex3f(-(longueur / 2.0f), 0.0f, (largeur / 2.0f));
	glVertex3f((longueur / 2.0f), 0.0f, (largeur / 2.0f));
	glVertex3f((longueur / 2.0f), 0.0f, -(largeur / 2.0f));
	glEnd();
}

void Salle::dessiner_mur(void)
{
	glPushMatrix();
	glBegin(GL_QUADS);
	glNormal3f(0.0, 1.0, 0.0);
	glVertex3f(-(longueur / 2.0f), -(largeur / 2.0f),0.0f);
	glVertex3f(-(longueur / 2.0f), (largeur / 2.0f), 0.0f);
	glVertex3f((longueur / 2.0f), (largeur / 2.0f), 0.0f);
	glVertex3f((longueur / 2.0f), -(largeur / 2.0f), 0.0f);
	glEnd();
}
