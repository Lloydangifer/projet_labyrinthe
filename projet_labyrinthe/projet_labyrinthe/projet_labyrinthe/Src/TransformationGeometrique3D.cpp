#include "..\Include\TransformationGeometrique3D.h"



TransformationGeometrique3D::TransformationGeometrique3D()
{
	clear();
}

TransformationGeometrique3D::TransformationGeometrique3D(double * t)
{
	int k = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			composantes[i][j] = t[k];
			k++;
		}
}

TransformationGeometrique3D::TransformationGeometrique3D(double ** t)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			composantes[i][j] = t[i][j];
}

TransformationGeometrique3D::TransformationGeometrique3D(TransformationGeometrique3D * tg)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			composantes[i][j] = tg->composantes[i][j];
}


TransformationGeometrique3D::~TransformationGeometrique3D()
{
}

void TransformationGeometrique3D::clear()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			composantes[i][j] = (i == j) ? 1.0 : 0.0;
}

void TransformationGeometrique3D::compose(TransformationGeometrique3D * tg)
{
	double aux[4][4];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			aux[i][j] = 0.0;
			for (int k = 0; k < 4; k++)
				aux[i][j] += tg->composantes[i][k] * composantes[k][j];
		}
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			composantes[i][j] = aux[i][j];
}

void TransformationGeometrique3D::compose(TransformationGeometrique3D * t1, TransformationGeometrique3D * t2)
{
	double c[4][4];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			c[i][j] = 0.0;
			for (int k = 0; k < 4; k++)
				c[i][j] += t1->composantes[i][k] * t2->composantes[k][j];
		}
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			this->composantes[i][j] = c[i][j];
}

void TransformationGeometrique3D::transforme(CoordonneesHomogenes3D * ch)
{
	double t[4];
	for (int i = 0; i < 4; i++) {
		t[i] = 0.0;
		for (int k = 0; k < 4; k++)
			t[i] += composantes[i][k] * ch->composantes[k];
	}
	for (int i = 0; i < 4; i++) {
		ch->composantes[i] = t[i];
	}
}
