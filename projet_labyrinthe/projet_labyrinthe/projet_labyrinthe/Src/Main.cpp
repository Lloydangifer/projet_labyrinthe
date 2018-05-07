#include <stdlib.h>
#include <stdio.h>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "..\Include\PNG\ChargePngFile.h"
#include "..\Include\Position3D.h"
#include "..\Include\Personnage.h"
#include "..\Include\SalleCouloir.h"

/* Etat des touches du clavier: true si appuyée, false sinon */
bool* keyStates = new bool[256];

/* Couleurs */
static const float blanc[] = { 1.0F, 1.0F, 1.0F, 1.0F };
static const float noir[] = { 0.0F, 0.0F, 0.0F, 1.0F };
static const float gris[] = { 0.5F, 0.5F, 0.5F, 1.0F };
static const float gris_clair[] = { 0.8F, 0.8F, 0.8F, 1.0F };
static const float jaune[] = { 1.0F, 1.0F, 0.0F, 1.0F };
static const float rouge[] = { 1.0F, 0.0F, 0.0F, 1.0F };
static const float vert[] = { 0.0F, 1.0F, 0.0F, 1.0F };
static const float bleu[] = { 0.0F, 0.0F, 1.0F, 1.0F };

/* Personnage */
Personnage *personnage;

/* Labyrinthe */
SalleCouloir *salle;

/* tableau des textures */
GLuint texID[2];

static void chargeTexture(unsigned int textureID, char *filename) {
	glBindTexture(GL_TEXTURE_2D, textureID);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	{
		int resolution_x;
		int resolution_y;
		unsigned char *img = chargeImagePng(filename, &resolution_x, &resolution_y);
		if (img) {
			glTexImage2D(GL_TEXTURE_2D, 0, 3, resolution_x, resolution_y, 0, GL_RGB, GL_UNSIGNED_BYTE, img);
			free(img);
		}
		else {
			printf("Erreur lors du chargement de l'image %d.\n", textureID);
		}
	}
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
}

/* Fonction d'initialisation des parametres     */
/* OpenGL ne changeant pas au cours de la vie   */
/* du programme                                 */

void init(void) {

	// On cache le curseur pour plus de confort visuel
	glutSetCursor(GLUT_CURSOR_NONE);

	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_AUTO_NORMAL);
	glShadeModel(GL_SMOOTH);

	/********************************* LUMIERES **********************************/

	glLightfv(GL_LIGHT0, GL_DIFFUSE, blanc);
	glLightfv(GL_LIGHT0, GL_SPECULAR, blanc);
	glLightfv(GL_LIGHT0, GL_AMBIENT, gris);

	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);

	/********************************* TEXTURES **********************************/

	//chargeTexture(texID[0], "texture_sol.png");
	//chargeTexture(texID[1], "texture_mur.png");
	//glEnable(GL_TEXTURE_2D);


}

/************** Scene dessinee *********************/

void scene(void) {
	Position3D character_pos = personnage->getPosition();
	GLfloat pos_l0[4] = { character_pos.x(), character_pos.y(), character_pos.z(), 1.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, pos_l0);
	glPushMatrix();
	salle->dessiner_salle();
	glPopMatrix();
}

/****************** Gestion des entrées clavier *********************/
void keyOperations(void) {
	static double a = 0.3;

	if (personnage)
	{
		if (keyStates['q'] && !keyStates['d']) {
			personnage->tourner(a);
		}
		else if (keyStates['d'] && !keyStates['q']) {
			personnage->tourner(-a);
		}

		if (keyStates['z'] && !keyStates['s']) {
			personnage->avancer();
		}
		else if (keyStates['s'] && !keyStates['z']) {
			personnage->reculer();
		}
	}
}

/* Fonction executee lors d'un rafraichissement */
/* de la fenetre de dessin                      */

void display(void) {

	int window_width = glutGet(GLUT_WINDOW_WIDTH); // Largeur de la fenêtre
	int window_height = glutGet(GLUT_WINDOW_HEIGHT); // Hauteur de la fenêtre

	keyOperations();

	Direction3D personnage_direction = personnage->getDirection();
	Position3D personnage_position = personnage->getPosition();

	glClearColor(0.0F, 0.0F, 0.0F, 1.0F);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	int width = window_width;
	int height = window_height;

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(80.0F, (float)width / height, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
	gluLookAt(personnage_position.x()                                    , personnage_position.y() + personnage->getHauteur() , personnage_position.z(),
		      personnage_position.x() + personnage_direction.dx() * 500.0, personnage_position.y() + personnage->getHauteur() , personnage_position.z() + personnage_direction.dz() * 500.0,
		      0.0, 1.0, 0.0);
	scene();
	glPopMatrix();
	glFlush();
	glutSwapBuffers();

	int error = glGetError();
	if (error != GL_NO_ERROR) {
		printf("Attention erreur %d\n", error);
	}
}


/********** Libération de la mémoire pour les objets de l'application *************/
void free_memory()
{
	if (personnage)
	{
		delete personnage;
		personnage = nullptr;
	}
	/*if (salle)
	{
		delete salle;
		salle = nullptr;
	}*/
}

/************ Vide la mémoire utilisée et quitte le programme **************/
void free_memory_and_exit()
{
	free_memory();
	if (keyStates)
	{
		delete keyStates;
		keyStates = nullptr;
	}

	exit(0);
}

/* Fonction executee lorsqu'aucun evenement     */
/* n'est en file d'attente                      */

void idle(void) {
	glutPostRedisplay();
}

/* Fonction executee lors d'un changement       */
/* de la taille de la fenetre OpenGL            */

void reshape_externe(int x, int y) {
	glViewport(0, 0, x, y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0F, (float)x / y, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

/********* Fonction appelée lorsqu'une touche du clavier est pressée **********/
void keyPressed(unsigned char key, int x, int y) {
	keyStates[key] = true; // L'état de la touche est actualisé	
	if (key >= 'A' && key <= 'Z') // support majuscules
		keyStates[key + 'a' - 'A'] = true;

	switch (key){
		case 27: // Touche Echap
		{
			free_memory_and_exit();
			break;
		}
	}
}

/********* Fonction appelée lorsqu'une touche du clavier est relâchée **********/
void keyUp(unsigned char key, int x, int y) {
	keyStates[key] = false; // L'état de la touche est actualisé 
	if (key >= 'A' && key <= 'Z') // support majuscules
		keyStates[key + 'a' - 'A'] = false;
}

/********* Initialisation du tableau de booléens pour les touches du clavier **********/
void initKeyStates(void) {
	for (int i = 0; i < 256; i++) {
		keyStates[i] = false; // Au début aucune touche n'est appuyée
	}
}

/************* Fonction principale *********************************/
int main(int argc, char **argv) {

	initKeyStates();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(900, 500);

	personnage = new Personnage();
	salle = new SalleCouloir();

	glutInitWindowPosition(0, 0);
	// Au lieu d'utiliser glutCreateWindow(), on utilise glutEnterGameMode() qui permet 
	//  d'avoir un mode plein écran optimisé (selon la doc)
	//glutEnterGameMode();
	glutCreateWindow("Fenetre");

	init(); // Initialisations openGL

	glutKeyboardFunc(keyPressed);
	glutKeyboardUpFunc(keyUp);
	glutReshapeFunc(reshape_externe);
	glutIdleFunc(idle);
	glutDisplayFunc(display);

	glutMainLoop();

	free_memory_and_exit();

	return(0);
}