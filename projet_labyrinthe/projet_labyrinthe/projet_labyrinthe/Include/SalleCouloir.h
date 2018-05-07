#pragma once

#include "Salle.h"

class SalleCouloir :
	public Salle {
public:
	SalleCouloir(void);
	SalleCouloir(Position3D pos);
	void dessiner_salle(void);
};