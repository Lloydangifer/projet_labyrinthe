#include "..\Include\Etage.h"

Etage::Etage(void)
{
	this->position = new Position3D();
	// on créé les salles en leur assignant une position
	this->creer_salles();
}

Etage::Etage(Position3D pos)
{
	this->position = pos;
	// on créé les salles en leur assignant une position
	this->creer_salles();
}

Etage::Etage(Position3D pos, int num_etage)
{
}

Etage::~Etage(void)
{
}

void Etage::dessiner_etage(void)
{
	for (int i = 0; i < 25; i++) {
		glPushMatrix();
		glTranslated(this->salles[i]->get_position().x(), this->salles[i]->get_position().y(), this->salles[i]->get_position().z());
		this->salles[i]->dessiner_salle();
		glPopMatrix();
	}
}

void Etage::creer_salles(void)
{
		this->salles[0] = new SalleCouloir(this->position);
		this->salles[1] = new SalleCouloir(new Position3D(this->position.x() + 5.0, this->position.y(), this->position.z()));
		this->salles[2] = new SalleCouloir(new Position3D(this->position.x() + 10.0, this->position.y(), this->position.z()));
		this->salles[3] = new SalleCouloir(new Position3D(this->position.x() + 15.0, this->position.y(), this->position.z()));
		this->salles[4] = new SalleCouloir(new Position3D(this->position.x() + 20.0, this->position.y(), this->position.z()));
		this->salles[5] = new SalleCouloir(new Position3D(this->position.x(), this->position.y(), this->position.z() + 5.0));
		this->salles[6] = new SalleCouloir(new Position3D(this->position.x() + 5.0, this->position.y(), this->position.z() + 5.0));
		this->salles[7] = new SalleCouloir(new Position3D(this->position.x() + 10.0, this->position.y(), this->position.z() + 5.0));
		this->salles[8] = new SalleCouloir(new Position3D(this->position.x() + 15.0, this->position.y(), this->position.z() + 5.0));
		this->salles[9] = new SalleCouloir(new Position3D(this->position.x() + 20.0, this->position.y(), this->position.z() + 5.0));
		this->salles[10] = new SalleCouloir(new Position3D(this->position.x(), this->position.y(), this->position.z()));
		this->salles[11] = new SalleCouloir(new Position3D(this->position.x() + 5.0, this->position.y(), this->position.z() + 10.0));
		this->salles[12] = new SalleCouloir(new Position3D(this->position.x() + 10.0, this->position.y(), this->position.z() + 10.0));
		this->salles[13] = new SalleCouloir(new Position3D(this->position.x() + 15.0, this->position.y(), this->position.z() +10.0));
		this->salles[14] = new SalleCouloir(new Position3D(this->position.x() + 20.0, this->position.y(), this->position.z() +10.0));
		this->salles[15] = new SalleCouloir(new Position3D(this->position.x(), this->position.y(), this->position.z() + 15.0));
		this->salles[16] = new SalleCouloir(new Position3D(this->position.x() + 5.0, this->position.y(), this->position.z() + 15.0));
		this->salles[17] = new SalleCouloir(new Position3D(this->position.x() + 10.0, this->position.y(), this->position.z() + 15.0));
		this->salles[18] = new SalleCouloir(new Position3D(this->position.x() + 15.0, this->position.y(), this->position.z() + 15.0));
		this->salles[19] = new SalleCouloir(new Position3D(this->position.x() + 20.0, this->position.y(), this->position.z() + 15.0));
		this->salles[20] = new SalleCouloir(new Position3D(this->position.x(), this->position.y(), this->position.z() + 20.0));
		this->salles[21] = new SalleCouloir(new Position3D(this->position.x() + 5.0, this->position.y(), this->position.z() + 20.0));
		this->salles[22] = new SalleCouloir(new Position3D(this->position.x() + 10.0, this->position.y(), this->position.z() + 20.0));
		this->salles[23] = new SalleCouloir(new Position3D(this->position.x() + 15.0, this->position.y(), this->position.z() + 20.0));
		this->salles[24] = new SalleCouloir(new Position3D(this->position.x() + 20.0, this->position.y(), this->position.z() + 20.0));
}

void Etage::set_position(Position3D pos)
{
	this->position = pos;
}
