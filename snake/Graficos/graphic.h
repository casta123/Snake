/*
 * graphic.h
 *
 *  Created on: 22/09/2010
 *      Author: Sebastian Perez Salas
 *      		Carlos Alejandro Ruiz Ramirez
 *      		Andres Castaño
 *      		Adriano Polo Lozado
 *
 * GNU/GPL General Public License - http://www.gnu.org/copyleft/gpl.html
 */

#ifndef GRAPHIC_H_
#define GRAPHIC_H_

//------------------------23/09/2010 CAR-------------------------------------------------------
#include "CPunto.h"
#include <GL/glut.h>

//Prototipos de esta libreria solo para dar mï¿½s orden y mas facilidad al trabajar


void crearCabeza(int x, int y, int orientacion);
void crearCabeza(Punto punto, int orientacion);
void crearPunto(int x, int y);
void crearPunto(Punto punto);

void crearCabeza(int x, int y, int orientacion, texturas *textur) {
	glPushMatrix();
	switch (orientacion) {
	case 0:
		glTranslatef((20.0 * x), (20.0 * y), 0.0);
		break;
	case 1:
		glRotatef(90.0, 0., 0., 0.1);
		glTranslatef((20.0 * y), (-(20.0 * x)-20), 0.0);
		break;
	case 2:
		glRotatef(180.0, 0., 0., 0.1);
		glTranslatef((-(20.0 * x)-20),(-(20.0 * y)-20), 0.0);
		break;
	case 3:
		glRotatef(270.0, 0., 0., 0.1);
		glTranslatef(-(20.0 * y)-20,(20.0 * x), 0.0);
		break;
	}
	glEnable(GL_TEXTURE_2D);
	glTexImage2D(GL_TEXTURE_2D, 0, textur->textura[7]->internalFormat, textur->textura[7]->sizeX,
			textur->textura[7]->sizeY, 0, textur->textura[7]->format, GL_UNSIGNED_BYTE,
			textur->textura[7]->data);
		glBegin(GL_POLYGON);
		glTexCoord2f(0.1875,0.375);
		glVertex2f(6, 0);
		glTexCoord2f(0.4375,0.375);
		glVertex2f(14, 0);
		glTexCoord2f(0.625,0.46875);
		glVertex2f(20, 3);
		glTexCoord2f(0.625,0.59375);
		glVertex2f(20, 7);
		glTexCoord2f(0.40625,1);
		glVertex2f(13, 20);
		glTexCoord2f(0.21875,1);
		glVertex2f(7, 20);
		glTexCoord2f(0,0.59375);
		glVertex2f(0, 7);
		glTexCoord2f(0,0.46875);
		glVertex2f(0, 3);
		glEnd();
		glTexImage2D(GL_TEXTURE_2D, 0, textur->textura[8]->internalFormat, textur->textura[8]->sizeX,
			textur->textura[8]->sizeY, 0, textur->textura[8]->format, GL_UNSIGNED_BYTE,
			textur->textura[8]->data);
		glBegin(GL_POLYGON);
		glTexCoord2f(0,0.625);
		glVertex2f(4, 8);
		glTexCoord2f(0.75,0.625);
		glVertex2f(16, 8);
		glTexCoord2f(0.75,1);
		glVertex2f(16, 14);
		glTexCoord2f(0,1);
		glVertex2f(4, 14);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glColor3f(1,0,0);
		glBegin(GL_POLYGON);
		glVertex2f(8,20);
		glVertex2f(12,20);
		glVertex2f(12,24);
		glVertex2f(11,22);
		glVertex2f(8,24);
		glEnd();
	glPopMatrix();
}

void crearCabeza(Punto punto, int orientacion, texturas *textur) {
	int x = int(punto.getX());
	int y = int(punto.getY());
	crearCabeza(x, y, orientacion,textur);
}

void crearPunto(int x, int y, texturas *textur) {
	glPushMatrix();
	glColor3f(1.0, 0.2745, 0.2745);
	glTranslatef((20.0 * x) , (20.0 * y) , 0.0); /////////Coordenadas corregidas
	glEnable(GL_TEXTURE_2D);
	glTexImage2D(GL_TEXTURE_2D, 0, textur->textura[6]->internalFormat,
			textur->textura[6]->sizeX,textur->textura[6]->sizeY, 0,
			textur->textura[6]->format, GL_UNSIGNED_BYTE,
			textur->textura[6]->data);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.1875, 0.375);
	glVertex2f(6, 0);
	glTexCoord2f(0.4375, 0.375);
	glVertex2f(14, 0);
	glTexCoord2f(0.625, 0.5625);
	glVertex2f(20, 6);
	glTexCoord2f(0.625, 0.8125);
	glVertex2f(20, 14);
	glTexCoord2f(0.4375, 1);
	glVertex2f(14, 20);
	glTexCoord2f(0.1875, 1);
	glVertex2f(6, 20);
	glTexCoord2f(0, 0.8125);
	glVertex2f(0, 14);
	glTexCoord2f(0, 0.5625);
	glVertex2f(0, 6);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void crearPunto(Punto punto,texturas *textur) {
	int x = int(punto.getX());
	int y = int(punto.getY());
	crearPunto(x, y,textur);
}

#endif /* GRAPHIC_H_ */
