/*
 * stdBoton.cpp
 *
 *  Created on: 8/11/2010
*      Author: Sebastian Perez Salas
 *      		Carlos Alejandro Ruiz Ramirez
 *      		Andres Castaño
 *      		Adriano Polo Lozado
 */
#include<GL/glut.h>
#include"../Graficos/AUX_RGBImageRec.h"
#include"../Graficos/CPunto.h"
#include<string>
#include<iostream>
using namespace std;
#include "stdBoton.h"
stdBoton::stdBoton() {

}
stdBoton::stdBoton(string id, Punto ubicacion, unsigned int width,
		unsigned int height, string texto, bool **activador,
		unsigned int numActivadores, AUX_RGBImageRec * textura) {
	this->id = id;
	this->ubicacion = ubicacion;
	this->width = width;
	this->height = height;
	this->texto = texto;
	this->activador = activador;
	this->numActivadores = numActivadores;
	this->textura = textura;
}
bool stdBoton::presionado(Punto mouse) {
	if (ubicacion.getX() <= mouse.getX() && ubicacion.getX() + width
			>= mouse.getX() && ubicacion.getY() <= mouse.getY()
			&& ubicacion.getY() + height >= mouse.getY())
		return true;
	else
		return false;
}
void stdBoton::dibujar() {
	if (this->textura) {
		glTexImage2D(GL_TEXTURE_2D, 0, textura->internalFormat, textura->sizeX,
				textura->sizeY, 0, textura->format, GL_UNSIGNED_BYTE,
				textura->data);
		glEnable(GL_TEXTURE_2D);
	}

	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(ubicacion.getX(), ubicacion.getY(), 1);
	glTexCoord2f(1, 0);
	glVertex3f(ubicacion.getX() + width, ubicacion.getY(), 1);
	glTexCoord2f(1, 1);
	glVertex3f(ubicacion.getX() + width, ubicacion.getY() + height, 1);
	glTexCoord2f(0, 1);
	glVertex3f(ubicacion.getX(), ubicacion.getY() + height, 1);
	glEnd();

	if (this->textura)
		glDisable(GL_TEXTURE_2D);

	glColor3f(1,1,1);
	glRasterPos2f(double(ubicacion.getX()) + double(width / 2) - 3.9 * double(
			texto.length()), ubicacion.getY() + height / 2 - 6);
	for (unsigned int i = 0; i < texto.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,
				*(this->texto.c_str() + i));
}
void stdBoton::activar() {
	if (activador)
		for (unsigned int i = 0; i < numActivadores; i++){
			*(activador[i]) = true;
		}
}
