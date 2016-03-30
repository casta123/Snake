/*
 * CCulebrita.h
 *
 *  Created on: 29/09/2010
*      Author: Sebastian Perez Salas
 *      		Carlos Alejandro Ruiz Ramirez
 *      		Andres Castaño
 *      		Adriano Polo Lozado
 */

#ifndef CCULEBRITA_H_
#define CCULEBRITA_H_
#include "CLista.h"
#include "CTexturas.h"
#include <GL/glut.h>



class Culebrita {
private:
	Cola cuerpo;
public:
	Culebrita();
	void dibujar(int direc, texturas *textur);
	void mover(Punto puntosig);
	void crecer(Punto puntosig);
	void reiniciar();
	bool colisionConCuerpo(Punto punto);
	bool colisionConPunto(Punto punto);
	Punto cabeza();

};


#endif /* CCULEBRITA_H_ */
