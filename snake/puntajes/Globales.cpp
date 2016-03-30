/*
 * Globales.cpp
 *
 *  Created on: 10/11/2010
 *      Author: Sebastian Perez Salas
 *      		Carlos Alejandro Ruiz Ramirez
 *      		Andres Castaño
 *      		Adriano Polo Lozado
 */
#include"CPuntaje.h"
#include "Globales.h"

#include<GL/glut.h>
#include"../Graficos/AUX_RGBImageRec.h"
#include<sstream>
Globales::Globales() {
	this->cargar();

}


int Globales::MasAlto(){
	int mayor=0;
	for(int i=0;i<10;i++){
		if(((this->puntajes+i)->getValor())>mayor) mayor=(this->puntajes+i)->getValor();
	}
	return mayor;
}

void Globales::dibujarGlobales(AUX_RGBImageRec * textura) {

	if (textura) {
		glTexImage2D(GL_TEXTURE_2D, 0, textura->internalFormat, textura->sizeX,
				textura->sizeY, 0, textura->format, GL_UNSIGNED_BYTE,
				textura->data);
		glEnable(GL_TEXTURE_2D);
	}
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(-110, -50, 0);
	glTexCoord2f(1, 0);
	glVertex3f(710, -50, 0);
	glTexCoord2f(1, 1);
	glVertex3f(710, 650, 0);
	glTexCoord2f(0, 1);
	glVertex3f(-110, 650, 0);

	glEnd();
	glDisable(GL_TEXTURE_2D);
	for (int i = 0; i < 10; i++) {
		glRasterPos2f(90, 500 -40 * (i) );
		glPushMatrix();

		stringstream textoamostrar;
		textoamostrar <<i + 1<<" .  "<< (this->puntajes + i)->getNombre() << "  "
				<< (this->puntajes + i)->getValor();

		for (unsigned int j = 0; j < textoamostrar.str().length(); j++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*(textoamostrar.str().c_str() + j));
		}
		glPopMatrix();
	}

}
bool Globales::esPuntajeAlto(int puntos) {
	this->cargar();
	for (int i = 0; i < 10; i++) {
		if ((this->puntajes + i)->getValor() < puntos)
			return true;
	}
	return false;
}
void Globales::insertar(CPuntaje puntajeAlto) {
	this->cargar();

	for (int i = 0; i < 10; i++) {
		if ((this->puntajes + i)->getValor() < puntajeAlto.getValor()) {
			for (int j = 8; j >= i; j--) {
				(this->puntajes + j)->setId(j + 1);
				*(this->puntajes + j + 1 )= *(this->puntajes + j);

			}
			puntajeAlto.setId(i + 1);
			*(this->puntajes + i) = puntajeAlto;
			this->guardar();
			return;
		}
	}
}

void Globales::cargar() {
	for (int i = 0; i < 10; i++) {
		(this->puntajes + i)->setId(i + 1);
		(this->puntajes + i)->Leer();
	}
}
void Globales::guardar() {
	for (int i = 0; i < 10; i++) {
		(this->puntajes + i)->setId(i+1);
		(this->puntajes + i)->Guardar();
	}
}
