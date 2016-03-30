/*
 * CPresa.cpp
 *
 *  Created on: 31/10/2010
 *      Author: Sebastian Perez Salas
 *      		Carlos Alejandro Ruiz Ramirez
 *      		Andres Castaño
 *      		Adriano Polo Lozado
 */
#include"Graficos/CPunto.h"
#include<GL/glut.h>
#include<time.h>
#include "CPresa.h"


#include <cstdlib>
using namespace std;
Presa::Presa(){
	srand(time(0));
	this->aleatorizar_presa();
}

Presa::Presa(int x,int y){
	ubicacion.setX(x);
	ubicacion.setY(y);
	ubicacion_en_vector=(900-30)+x-(y*30);
}
Punto Presa::getpunto(){
	return ubicacion;
}
void Presa::aleatorizar_presa(){
	int N=28;
	int M=1;
	int ax= rand () % (N-M+1) + M;// devuelve un nuemro aleatorio entre 1 y 28  teniendo en cuenta que los numeros 0 y 29 siempre van a pertenecera los bordes del mapa
	int ay= rand () % (N-M+1) + M;
	ubicacion.set(ax,ay);
}
void  Presa::dibujar(){
	int x=int(ubicacion.getX());
	int y=int(ubicacion.getY());
	glPushMatrix();
		glTranslatef((20.0 * x), (20.0 * y), 0.0);
		//relleno
		glBegin(GL_TRIANGLES);
		glColor3f(0.9803, 1, 0.12549);
		glVertex2f(7.55, 13);
		glVertex2f(12.45, 13);
		glVertex2f(10, 20);
		glVertex2f(7.55, 13);
		glVertex2f(0, 13);
		glVertex2f(5.95, 8.44);
		glVertex2f(10, 5.35);
		glVertex2f(3, 0);
		glVertex2f(5.95, 8.44);
		glVertex2f(14.04, 8.44);
		glVertex2f(17, 0);
		glVertex2f(10, 5.35);
		glVertex2f(13.45, 13);
		glVertex2f(20, 13);
		glVertex2f(14.04, 5.35);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(0.9803, 1, 0.12549);
		glVertex2f(5.95, 8.44);
		glVertex2f(7.55, 13);
		glVertex2f(12.45, 13);
		glVertex2f(14.04, 8.44);
		glVertex2f(10, 5.35);
		glEnd();
		glLineWidth(0.5);
		glBegin(GL_LINES);
		glColor3d(0.496, 0.496, 0.98);
		glColor3f(0, 0, 0);
		glVertex2f(12.45, 13);
		glVertex2f(10, 20);
		glVertex2f(10, 20);
		glVertex2f(7.55, 13);
		glVertex2f(7.55, 13);
		glVertex2f(0, 13);
		glVertex2f(0, 13);
		glVertex2f(5.95, 8.44);
		glVertex2f(5.95, 8.44);
		glVertex2f(3, 0);
		glVertex2f(3.0, 0.0);
		glVertex2f(10, 5.35);
		glVertex2f(10, 5.35);
		glVertex2f(17, 0);
		glVertex2f(17, 0);
		glVertex2f(14.04, 8.44);
		glVertex2f(14.04, 8.44);
		glVertex2f(20, 13);
		glVertex2f(20, 13);
		glVertex2f(12.45, 13);
		glEnd();
		glPopMatrix();
}
