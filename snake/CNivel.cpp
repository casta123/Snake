/*
 * CNivel.cpp
 *
 *  Created on: 27/10/2010
 *      Author: Sebastian Perez Salas
 *      		Carlos Alejandro Ruiz Ramirez
 *      		Andres Castaño
 *      		Adriano Polo Lozado
 */

#include "CNivel.h"
#include<GL/glut.h>
#include <sstream>
#include<string>
#include<string.h>
#include<fstream>
#include<iostream>
#include"Graficos/CPunto.h"
using namespace std;

CNivel::CNivel() {

	this->nivel = new int*[6]; //Creamos un arreglo de punteros de 6 punteros de enteros
	this->LeerNiveles();
	this->actual = *(this->nivel);

}

void CNivel::LeerNiveles() {

	for (int i = 1; i <= 6; i++) { //Creamos un ciclo para recorrer los 6 niveles del juego

		stringstream streamarchivo; //Generamos un stream para concatenar el nombre del archivo
		streamarchivo << "Niv" << i << ".snk";	// Generamos el nombre del archivo
		ifstream nivel((streamarchivo.str()).c_str(), ios::in);	///Abrimos el archivo con el nombre generado en modo entrada
		if (nivel.good()) {	///Si el archivo es correcto procedemos a cargarlo a la memoria ram

			stringstream auxiliar; //Creamos stream en el cual guerdaremos solo los numeros que aparecen en el archivo
			char linea[60];	//Creamos un arreglo de caracteres en el que guardaremos una linea completa del archivo
			for (int j = 0; j < 30; j++) {//Recorremos cada linea del archivo
				nivel >> linea; //Extraemos la linea del archivo y la guardamos en el arreglo de caracteres
				for (int k = 0; k < 60; k += 2) { //En auxiliar solo guardamos los datos representativos eliminando , y saltos de linea
					auxiliar << linea[k];
				}

			}

			//en este punto auxiliar tiene guardado todo el nivel en un arreglo de enteros
			//, pero no nos sirve por que tiene que ser entero, asï¿½ que lo transformamos

			*(this->nivel + i -1) = new int[900];//Asignamos un direccion de memoria al arreglo de punteros

			for (int j = 0; j < 900; j++) {
				stringstream posicion;
				posicion << *( (auxiliar.str()).c_str() + j); //Recorremos la cadena de caracteres
				//Comprobamos que el caracter que se estÃ¡ cargando si sea un numero
				if( *((posicion.str()).c_str()) >= '0' && *(posicion.str()).c_str() <= '9')
				//Como es un numero lo agregamos al arreglo en su posicion correspondiente
					posicion >> *(*(this->nivel + i -1 ) + j);
				else{
					//Si encuentra algo que no sea un caracter para de cargar el archivo
					cout<<"Caracter desconocido al leer "<<(streamarchivo.str()).c_str()<<endl;
					break;
				}
			}

		} else { //Si no encuentra el archivo, el puntero se le asigna un valor nulo
			*(this->nivel + i) = NULL;
			cout << "Error al leer el archivo " << streamarchivo.str() << endl;
		}
	}

}
void CNivel::Liberar() {
	for (int i = 0; i < 5; i++) {
		delete (this->nivel + i);
	}
}

int * CNivel::Actual() {
	return actual;
}
void CNivel::siguiente() {
	if (cursor < 5) {
		cursor++;
	}
	this->actual = *(this->nivel + cursor);
}
void CNivel::anterior() {
	if (cursor > 0)
		cursor--;
	this->actual = *(this->nivel + cursor);
}
void CNivel::primero() {
	cursor = 0;
	this->actual = *(this->nivel + cursor);
}
void CNivel::Linea(int a, int b, int c, int d) {
	glBegin(GL_LINES);
	glVertex2f(a, b);
	glVertex2f(c, d);
	glEnd();
}

bool CNivel::existeActual(Punto ubicacion){

	int x=int(ubicacion.getX()); //guarda ubicacion del punto en posicion x como entero
	int y=int(ubicacion.getY()); //guarda ubicacion del punto en posicion x como entero
	int pos=(900-30)+x-(y*30); //defina la posicion del punto en el arreglo

	if(*(actual + pos)!=0){ //retorna verdas si el  valor cgaurdado en la matriz es distinti de 0
			return true;
		}

	return false;
}
void CNivel::DibujarNivel(texturas *textur) {
	int *nivel = this->actual;
	glEnable(GL_TEXTURE_2D);
	glTexImage2D(GL_TEXTURE_2D, 0, textur->textura[1]->internalFormat, textur->textura[1]->sizeX,
					textur->textura[1]->sizeY, 0, textur->textura[1]->format, GL_UNSIGNED_BYTE,
					textur->textura[1]->data);

	glBegin(GL_POLYGON);
				glTexCoord2f(0.0, 0.0);
				glVertex3f(0.0,0.0, 0);
				glTexCoord2f(1.0, 0.0);
				glVertex3f(600,0, 0);
				glTexCoord2f(1.0, 1.0);
				glVertex3f(600,600, 0);
				glTexCoord2f(0.0, 1.0);
				glVertex3f(0,600,0);
				glEnd();

	//coloca la textura de fondo hierba1 en su correspondiente lugar
	glTexImage2D(GL_TEXTURE_2D, 0, textur->textura[2]->internalFormat, textur->textura[2]->sizeX,
			textur->textura[2]->sizeY, 0, textur->textura[2]->format, GL_UNSIGNED_BYTE,
			textur->textura[2]->data);

	glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 1.0);
		glVertex3f(0.0,0.0, 0);
		glTexCoord2f(0.0, 0.0);
		glVertex3f(0,-50, 0);
		glTexCoord2f(1.0, 0.0);
		glVertex3f(600,-50, 0);
		glTexCoord2f(1.0, 1.0);
		glVertex3f(600,0,0);
		glEnd();

	glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0);
		glVertex3f(0, 600, 0);
		glTexCoord2f(1.0, 0.0);
		glVertex3f(600, 600, 0);
		glTexCoord2f(1.0, 1.0);
		glVertex3f(600, 650, 0);
		glTexCoord2f(0.0, 1.0);
		glVertex3f(0, 650, 0);
		glEnd();

		//coloca la textura de fondo hierba2 en su correspondiente lugar
		glTexImage2D(GL_TEXTURE_2D, 0, textur->textura[3]->internalFormat, textur->textura[3]->sizeX,
					textur->textura[3]->sizeY, 0, textur->textura[3]->format, GL_UNSIGNED_BYTE,
					textur->textura[3]->data);

			glBegin(GL_POLYGON);
				glTexCoord2f(1.0, 0.0);
				glVertex3f(0,-50, 0);
				glTexCoord2f(0.0, 0.0);
				glVertex3f(-110,-50, 0);
				glTexCoord2f(0.0, 1.0);
				glVertex3f(-110,650, 0);
				glTexCoord2f(1.0, 1.0);
				glVertex3f(0,650,0);
				glEnd();

			glBegin(GL_POLYGON);
				glTexCoord2f(0.0, 0.0);
				glVertex3f(600, -50, 0);
				glTexCoord2f(1.0, 0.0);
				glVertex3f(710, -50, 0);
				glTexCoord2f(1.0, 1.0);
				glVertex3f(710, 650, 0);
				glTexCoord2f(0.0, 1.0);
				glVertex3f(600, 650, 0);
				glEnd();


	glDisable(GL_TEXTURE_2D);

	//Dibujar las lineas de los bordes
	//crea las lineas verticales
	for (int i = 20; i < 600; i += 20) {
		glLineWidth(1.4);
		glColor3f(0.764705, 0.764705, 0.764705);
		this->Linea(i, 0, i, 600);
	}

	//crea las lineas horizontales
	for (int i = 20; i < 600; i += 20) {
		glLineWidth(1.4);
		glColor3f(0.764705, 0.764705, 0.764705);
		this->Linea(0, i, 600, i);
	}

	//Crea los bordes
	glLineWidth(2.3);
	glColor3f(0, 0, 0);
	this->Linea(0, 0, 0, 600);
	this->Linea(0, 600, 600, 600);
	this->Linea(600, 0, 600, 600);
	this->Linea(0, 0, 600, 0);


	//dibujar la pantalla segun el nivel
	int x, y = -1;
	glEnable(GL_TEXTURE_2D);
	glTexImage2D(GL_TEXTURE_2D, 0, textur->textura[0]->format, textur->textura[0]->sizeX,
			textur->textura[0]->sizeY, 0, textur->textura[0]->format, GL_UNSIGNED_BYTE,
			textur->textura[0]->data);

	for (int i = 900; i > 0; i--) {
		if (i % 30 == 0) {
			x = 29;
			y++;
		}
		switch (nivel[i - 1]) {
		case 1:
			glBegin(GL_POLYGON);
			glTexCoord2f(0.0, 1.0);
			glVertex3f((x * 20) , (y * 20) + 20, 0);
			glTexCoord2f(0.0, 0.0);
			glVertex3f((x * 20), (y * 20) , 0);
			glTexCoord2f(1.0, 0.0);
			glVertex3f((x * 20) + 20, (y * 20) , 0);
			glTexCoord2f(1.0, 1.0);
			glVertex3f((x * 20) + 20, (y * 20) + 20, 0);
			glEnd();

			break;

		}
		x--;
	}
	glDisable(GL_TEXTURE_2D);


	/*
	y = -1;
	glTexImage2D(GL_TEXTURE_2D, 0, 3, textur->textura[0]->sizeX,
						textur->textura[0]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE,
						textur->textura[0]->data);
	for (int i = 900; i > 0; i--) {
		if (i % 30 == 0) {
			x = 29;
			y++;
		}
		switch (nivel[i - 1]) {
		 case 1:
			//crea el cuadro individual para hacer el obstaculo
			glBegin(GL_POLYGON);
			glNormal3f(0, 0, 1);

			glTexCoord2f(0.0, 1.0);
			glVertex3f((x * 20) + 1, (y * 20) + 19, 0);

			glTexCoord2f(0.0, 0.0);
			glVertex3f((x * 20) + 1, (y * 20) + 1, 0);

			glTexCoord2f(1.0, 0.0);
			glVertex3f((x * 20) + 19, (y * 20) + 1, 0);

			glTexCoord2f(1.0, 1.0);
			glVertex3f((x * 20) + 19, (y * 20) + 19, 0);
			glEnd();

			break;

		}
		x--;
	}
	glDisable(GL_TEXTURE_2D);

	*/

}

