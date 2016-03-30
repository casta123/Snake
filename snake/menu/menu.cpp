/*
 * menu.cpp
 *
 *  Created on: 8/11/2010
 *      Author: Sebastian Perez Salas
 *      		Carlos Alejandro Ruiz Ramirez
 *      		Andres Castaño
 *      		Adriano Polo Lozado
 */
#include<iostream>
#include<GL/glut.h>
#include "Menu.h"
#include "ListaBoton.h"
#include "../Graficos/AUX_RGBImageRec.h"
Menu::Menu(int PantallaWidth, int PantallaHeight, bool enMenu, int xIni,
		int xFin, int yIni, int yFin, AUX_RGBImageRec * backgr) {

	this->PantallaWidth = PantallaWidth;
	this->PantallaHeight = PantallaHeight;
	this->PantallaInicialWidth = PantallaWidth;
	this->PantallaInicialHeight = PantallaHeight;
	this->enMenu = enMenu;
	this->xIni = xIni;
	this->yIni = yIni;
	this->xFin = xFin;
	this->yFin = yFin;
	this->backgr = backgr;

}

void Menu::enClick(double posicionX, double posicionY) {
	posicionX = double((posicionX * double(PantallaInicialWidth) / double(
			PantallaWidth)) + xIni);

	posicionY = double(-1 * (posicionY * double(PantallaInicialHeight)
			/ double(PantallaHeight)) + yFin);

	Punto posicion(posicionX, posicionY);
	if (botones.tamano())
		botones.irPrimero();
	for (;;) {
		if (botones.actual().presionado(posicion)) {
			botones.actual().activar();
		}
		if (botones.esUltimo())
			break;
		else
			botones.siguiente();
	}

}
void Menu::enRedimension(int ancho, int alto) {
	this->PantallaWidth = ancho;
	this->PantallaHeight = alto;
}

void Menu::insertarBoton(stdBoton boton) {
	this->botones.insertar(boton);
}

void Menu::dibujar() {
	if (this->backgr) {
		glTexImage2D(GL_TEXTURE_2D, 0, backgr->internalFormat, backgr->sizeX,
				backgr->sizeY, 0, backgr->format, GL_UNSIGNED_BYTE,
				backgr->data);
		glEnable(GL_TEXTURE_2D);
	}

	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(xIni, yIni, 0);
	glTexCoord2f(1, 0);
	glVertex3f(xFin, yIni, 0);
	glTexCoord2f(1, 1);
	glVertex3f(xFin, yFin, 0);
	glTexCoord2f(0, 1);
	glVertex3f(xIni, yFin, 0);
	glEnd();
	if (this->backgr)
		glDisable(GL_TEXTURE_2D);
	//Dibujamos los botones
	if (botones.tamano())
		botones.irPrimero();
	for (;;) {
		botones.actual().dibujar();
		if (botones.esUltimo())
			break;
		else
			botones.siguiente();
	}
}
